// MetalRenderer.swift
// Renders BSP mesh + MDL model. STEP 16C.
// AetherEngine-iOS · Clean-room.

import MetalKit
import SwiftUI
import simd

struct Uniforms {
    var model:      simd_float4x4
    var view:       simd_float4x4
    var proj:       simd_float4x4
    var lightDir:   simd_float3
    var pad0:       Float = 0
    var baseColor:  simd_float4
    var useTexture: Float = 0
    var pad1:       Float = 0
    var pad2:       Float = 0
    var pad3:       Float = 0
}

final class MetalRenderer: NSObject, MTKViewDelegate {
    let device: MTLDevice
    let queue:  MTLCommandQueue

    // BSP pipeline
    var bspPipeline:  MTLRenderPipelineState?
    var depthState:   MTLDepthStencilState?
    var samplerState: MTLSamplerState?

    // BSP buffers
    var vertexBuffer: MTLBuffer?
    var indexBuffer:  MTLBuffer?
    var indexCount:   Int = 0

    // Texture atlas
    var atlasTexture: MTLTexture?
    var hasTexture:   Bool = false

    // MDL pipeline + buffers
    var mdlPipeline:   MTLRenderPipelineState?
    var mdlVertexBuf:  MTLBuffer?
    var mdlTexture:    MTLTexture?
    var mdlIndexBuf:   MTLBuffer?
    var mdlIndexCount: Int = 0
    var mdlVertexCount: Int = 0
    var hasMdl:        Bool = false
    private var loadedViewmodelPath: String = ""
    private var viewmodelScale: Float = 1.0

    private var lastTime: CFTimeInterval = CACurrentMediaTime()

    init?(mtkView: MTKView) {
        guard let dev = mtkView.device ?? MTLCreateSystemDefaultDevice(),
              let q   = dev.makeCommandQueue() else { return nil }
        self.device = dev
        self.queue  = q
        super.init()
        mtkView.delegate = self
        mtkView.colorPixelFormat = .bgra8Unorm
        mtkView.depthStencilPixelFormat = .depth32Float
        mtkView.clearColor = MTLClearColor(red: 0.05, green: 0.05, blue: 0.08, alpha: 1.0)
        mtkView.preferredFramesPerSecond = 60
        mtkView.isPaused = false
        mtkView.enableSetNeedsDisplay = false

        buildBspPipeline(mtkView: mtkView)
        buildMdlPipeline(mtkView: mtkView)
        buildDepthState()
        buildSampler()

        let opaque = Unmanaged.passUnretained(mtkView).toOpaque()
        engine_renderer_attach_metal(opaque)
    }

    // MARK: - BSP pipeline
    private func buildBspPipeline(mtkView: MTKView) {
        guard let lib = device.makeDefaultLibrary(),
              let vfn = lib.makeFunction(name: "aether_vertex_main"),
              let ffn = lib.makeFunction(name: "aether_fragment_main") else {
            print("[MetalRenderer] BSP shader funcs missing"); return
        }

        let vd = MTLVertexDescriptor()
        vd.attributes[0].format = .float3
        vd.attributes[0].offset = 0
        vd.attributes[0].bufferIndex = 0
        vd.attributes[1].format = .float3
        vd.attributes[1].offset = 12
        vd.attributes[1].bufferIndex = 0
        vd.attributes[2].format = .float2
        vd.attributes[2].offset = 24
        vd.attributes[2].bufferIndex = 0
        vd.layouts[0].stride = 32
        vd.layouts[0].stepFunction = .perVertex

        let d = MTLRenderPipelineDescriptor()
        d.vertexFunction = vfn
        d.fragmentFunction = ffn
        d.vertexDescriptor = vd
        d.colorAttachments[0].pixelFormat = mtkView.colorPixelFormat
        d.depthAttachmentPixelFormat      = mtkView.depthStencilPixelFormat

        do { bspPipeline = try device.makeRenderPipelineState(descriptor: d) }
        catch { print("[MetalRenderer] BSP pipeline error: \(error)") }
    }

    // MARK: - MDL pipeline
    private func buildMdlPipeline(mtkView: MTKView) {
        guard let lib = device.makeDefaultLibrary(),
              let vfn = lib.makeFunction(name: "aether_model_vertex"),
              let ffn = lib.makeFunction(name: "aether_model_fragment") else {
            print("[MetalRenderer] MDL shader funcs missing"); return
        }

        let vd = MTLVertexDescriptor()
        vd.attributes[0].format = .float3
        vd.attributes[0].offset = 0
        vd.attributes[0].bufferIndex = 0
        vd.attributes[1].format = .float3
        vd.attributes[1].offset = 12
        vd.attributes[1].bufferIndex = 0
        vd.attributes[2].format = .float2
        vd.attributes[2].offset = 24
        vd.attributes[2].bufferIndex = 0
        vd.layouts[0].stride = 32
        vd.layouts[0].stepFunction = .perVertex

        let d = MTLRenderPipelineDescriptor()
        d.vertexFunction = vfn
        d.fragmentFunction = ffn
        d.vertexDescriptor = vd
        d.colorAttachments[0].pixelFormat = mtkView.colorPixelFormat
        d.depthAttachmentPixelFormat      = mtkView.depthStencilPixelFormat

        do {
            mdlPipeline = try device.makeRenderPipelineState(descriptor: d)
            print("[MetalRenderer] MDL pipeline built OK")
        } catch {
            print("[MetalRenderer] MDL pipeline error: \(error)")
        }
    }

    private func buildDepthState() {
        let d = MTLDepthStencilDescriptor()
        d.depthCompareFunction = .less
        d.isDepthWriteEnabled  = true
        depthState = device.makeDepthStencilState(descriptor: d)
    }

    private func buildSampler() {
        let s = MTLSamplerDescriptor()
        s.minFilter = .linear
        s.magFilter = .linear
        s.sAddressMode = .clampToEdge
        s.tAddressMode = .clampToEdge
        samplerState = device.makeSamplerState(descriptor: s)
    }

    // MARK: - Viewmodel
    private func refreshViewmodelIfNeeded(force: Bool = false) {
        let visible = engine_game_viewmodel_visible()
        let path = String(cString: engine_game_viewmodel_path())
        guard !path.isEmpty else {
            loadedViewmodelPath = ""
            return
        }
        if force || path != loadedViewmodelPath {
            if engine_game_refresh_viewmodel() != 0 {
                loadedViewmodelPath = path
                let mn = UnsafeMutablePointer<Float>.allocate(capacity: 3)
                let mx = UnsafeMutablePointer<Float>.allocate(capacity: 3)
                let ctr = UnsafeMutablePointer<Float>.allocate(capacity: 3)
                engine_mdl_mesh_get_bounds(mn, mx, ctr)
                let dx = abs(mx[0] - mn[0])
                let dy = abs(mx[1] - mn[1])
                let dz = abs(mx[2] - mn[2])
                let extent = max(dx, max(dy, dz))
                viewmodelScale = extent > 0.001 ? min(1.0, 28.0 / extent) : 1.0
                mn.deallocate(); mx.deallocate(); ctr.deallocate()
                uploadMdlMesh()
            }
        }
    }

    private func viewmodelMatrix(eye: simd_float3, forward: simd_float3, recoilPitch: Float, recoilYaw: Float) -> simd_float4x4 {
        let f = simd_normalize(forward)
        var right = simd_normalize(simd_cross(f, simd_float3(0, 0, 1)))
        if simd_length_squared(right) < 0.0001 { right = simd_float3(0, 1, 0) }
        var up = simd_normalize(simd_cross(right, f))

        let pitch = recoilPitch * .pi / 180.0
        let yaw = recoilYaw * .pi / 180.0
        let f2 = simd_normalize(f * cos(pitch) + up * sin(pitch))
        up = simd_normalize(simd_cross(f2, right))
        right = simd_normalize(right * cos(yaw) + f2 * sin(yaw))

        var off = [Float](repeating: 0, count: 3)
        engine_game_viewmodel_offset(&off)
        let position = eye + f2 * 24.0 + right * (off[0] + 5.0) + up * (off[2] - 4.0)
        let yOffset = off[1]

        var m = matrix_identity_float4x4
        // The MDL shader remaps (x,y,z) -> (x,z,y), so columns 1/2 are
        // deliberately ordered as up/right to preserve GoldSrc axes.
        m.columns.0 = simd_float4(f2 * viewmodelScale, 0)
        m.columns.1 = simd_float4(up * viewmodelScale, 0)
        m.columns.2 = simd_float4(right * viewmodelScale, 0)
        m.columns.3 = simd_float4(position + up * yOffset, 1)
        return m
    }

    private func drawViewmodel(_ enc: MTLRenderCommandEncoder, eye: simd_float3, forward: simd_float3, view: simd_float4x4, proj: simd_float4x4) {
        guard let pipeline = mdlPipeline, let vb = mdlVertexBuf, let ib = mdlIndexBuf, mdlIndexCount > 0, engine_game_viewmodel_visible() else { return }
        enc.setRenderPipelineState(pipeline)
        let model = viewmodelMatrix(eye: eye, forward: forward, recoilPitch: engine_game_recoil_pitch(), recoilYaw: engine_game_recoil_yaw())
        var U = Uniforms(model: model, view: view, proj: proj,
                         lightDir: simd_normalize(simd_float3(0.3, 0.8, 0.5)),
                         pad0: 0, baseColor: simd_float4(1, 1, 1, 1),
                         useTexture: mdlTexture != nil ? 1.0 : 0.0, pad1: 0, pad2: 0, pad3: 0)
        enc.setDepthStencilState(viewmodelDepthState())
        enc.setVertexBuffer(vb, offset: 0, index: 0)
        enc.setVertexBytes(&U, length: MemoryLayout<Uniforms>.stride, index: 1)
        enc.setFragmentBytes(&U, length: MemoryLayout<Uniforms>.stride, index: 1)
        if let tex = mdlTexture, let ss = samplerState {
            enc.setFragmentTexture(tex, index: 0)
            enc.setFragmentSamplerState(ss, index: 0)
        }
        enc.drawIndexedPrimitives(type: .triangle, indexCount: mdlIndexCount, indexType: .uint32, indexBuffer: ib, indexBufferOffset: 0)
        enc.setDepthStencilState(depthState)
    }

    private func viewmodelDepthState() -> MTLDepthStencilState? {
        let d = MTLDepthStencilDescriptor()
        d.depthCompareFunction = .always
        d.isDepthWriteEnabled = false
        return device.makeDepthStencilState(descriptor: d)
    }

    // MARK: - Uploads
    func uploadMeshFromEngine() {
        uploadBspMesh()
        uploadAtlas()
        uploadMdlMesh()
        refreshViewmodelIfNeeded(force: true)
        engine_player_spawn_at_mesh_center()
        print("[MetalRenderer] Upload complete (BSP=\(indexCount > 0), MDL=\(hasMdl))")
    }

    private func uploadBspMesh() {
        let vCount = Int(engine_bsp_mesh_vertex_count())
        let iCount = Int(engine_bsp_mesh_index_count())
        guard vCount > 0, iCount > 0 else { return }

        var vData = [Float](repeating: 0, count: vCount * 8)
        _ = vData.withUnsafeMutableBufferPointer { buf -> Int32 in
            Int32(engine_bsp_mesh_copy_vertices(buf.baseAddress, Int32(vCount)))
        }
        vertexBuffer = device.makeBuffer(bytes: vData,
                                          length: vCount * 32,
                                          options: .storageModeShared)

        var iData = [UInt32](repeating: 0, count: iCount)
        _ = iData.withUnsafeMutableBufferPointer { buf -> Int32 in
            Int32(engine_bsp_mesh_copy_indices(buf.baseAddress, Int32(iCount)))
        }
        indexBuffer = device.makeBuffer(bytes: iData,
                                         length: iCount * 4,
                                         options: .storageModeShared)
        indexCount = iCount
    }

    private func uploadAtlas() {
        let w = Int(engine_texture_atlas_width())
        let h = Int(engine_texture_atlas_height())
        guard w > 0, h > 0 else { hasTexture = false; return }
        let byteCount = w * h * 4
        var rgba = [UInt8](repeating: 0, count: byteCount)
        let copied = rgba.withUnsafeMutableBufferPointer { buf -> Int32 in
            Int32(engine_texture_atlas_copy_rgba(buf.baseAddress, Int32(byteCount)))
        }
        guard copied == byteCount else { hasTexture = false; return }

        let td = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: .rgba8Unorm,
                                                          width: w, height: h, mipmapped: false)
        td.usage = .shaderRead
        td.storageMode = .shared
        guard let tex = device.makeTexture(descriptor: td) else { hasTexture = false; return }
        tex.replace(region: MTLRegionMake2D(0, 0, w, h),
                    mipmapLevel: 0,
                    withBytes: rgba,
                    bytesPerRow: w * 4)
        atlasTexture = tex
        hasTexture = true
        print("[MetalRenderer] Atlas \(w)x\(h) uploaded")
    }

    private func uploadMdlMesh() {
        let vCount = Int(engine_mdl_mesh_vertex_count())
        let tCount = Int(engine_mdl_mesh_triangle_count())
        guard vCount > 0, tCount > 0 else {
            hasMdl = false
            print("[MetalRenderer] No MDL mesh to upload")
            return
        }

        var pData = [Float](repeating: 0, count: vCount * 3)
        _ = pData.withUnsafeMutableBufferPointer { buf -> Int32 in
            Int32(engine_mdl_mesh_copy_positions(buf.baseAddress, Int32(vCount * 3)))
        }
        var nData = [Float](repeating: 0, count: vCount * 3)
        _ = nData.withUnsafeMutableBufferPointer { buf -> Int32 in
            Int32(engine_mdl_mesh_copy_normals(buf.baseAddress, Int32(vCount * 3)))
        }

        var uvData = [Float](repeating: 0, count: vCount * 2)
        _ = uvData.withUnsafeMutableBufferPointer { buf -> Int32 in
            Int32(engine_mdl_mesh_copy_uvs(buf.baseAddress, Int32(vCount * 2)))
        }

        var interleaved = [Float](repeating: 0, count: vCount * 8)
        for i in 0..<vCount {
            interleaved[i*8 + 0] = pData[i*3 + 0]
            interleaved[i*8 + 1] = pData[i*3 + 1]
            interleaved[i*8 + 2] = pData[i*3 + 2]
            interleaved[i*8 + 3] = nData[i*3 + 0]
            interleaved[i*8 + 4] = nData[i*3 + 1]
            interleaved[i*8 + 5] = nData[i*3 + 2]
            interleaved[i*8 + 6] = uvData[i*2 + 0]
            interleaved[i*8 + 7] = uvData[i*2 + 1]
        }
        mdlVertexBuf = device.makeBuffer(bytes: interleaved,
                                          length: vCount * 32,
                                          options: .storageModeShared)

        let tw = engine_mdl_mesh_texture_width()
        let th = engine_mdl_mesh_texture_height()
        mdlTexture = nil
        if tw > 0 && th > 0 {
            var rgba = [UInt8](repeating: 0, count: Int(tw * th * 4))
            let copied = rgba.withUnsafeMutableBufferPointer { buf -> Int32 in
                Int32(engine_mdl_mesh_copy_texture_rgba(buf.baseAddress, Int32(rgba.count)))
            }
            if copied == Int32(rgba.count) {
                let td = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: .rgba8Unorm,
                                                                   width: Int(tw), height: Int(th),
                                                                   mipmapped: false)
                td.usage = [.shaderRead]
                if let tex = device.makeTexture(descriptor: td) {
                    tex.replace(region: MTLRegionMake2D(0, 0, Int(tw), Int(th)),
                                mipmapLevel: 0, withBytes: rgba, bytesPerRow: Int(tw) * 4)
                    mdlTexture = tex
                }
            }
        }

        var iData = [UInt32](repeating: 0, count: tCount * 3)
        _ = iData.withUnsafeMutableBufferPointer { buf -> Int32 in
            Int32(engine_mdl_mesh_copy_indices(buf.baseAddress, Int32(tCount * 3)))
        }
        mdlIndexBuf = device.makeBuffer(bytes: iData,
                                         length: tCount * 3 * 4,
                                         options: .storageModeShared)
        mdlIndexCount  = tCount * 3
        mdlVertexCount = vCount
        hasMdl = true
        print("[MetalRenderer] MDL mesh uploaded: \(vCount) verts, \(tCount) tris")
    }

    private func updateAnimatedMDLBuffer() {
        guard hasMdl, let vb = mdlVertexBuf, mdlVertexCount > 0 else { return }
        var pData = [Float](repeating: 0, count: mdlVertexCount * 3)
        var nData = [Float](repeating: 0, count: mdlVertexCount * 3)
        let pc = pData.withUnsafeMutableBufferPointer { buf -> Int32 in
            Int32(engine_mdl_mesh_copy_skinned_positions(buf.baseAddress, Int32(pData.count)))
        }
        let nc = nData.withUnsafeMutableBufferPointer { buf -> Int32 in
            Int32(engine_mdl_mesh_copy_skinned_normals(buf.baseAddress, Int32(nData.count)))
        }
        guard pc == Int32(pData.count), nc == Int32(nData.count) else { return }
        let ptr = vb.contents().bindMemory(to: Float.self, capacity: mdlVertexCount * 8)
        for i in 0..<mdlVertexCount {
            ptr[i*8+0] = pData[i*3+0]
            ptr[i*8+1] = pData[i*3+1]
            ptr[i*8+2] = pData[i*3+2]
            ptr[i*8+3] = nData[i*3+0]
            ptr[i*8+4] = nData[i*3+1]
            ptr[i*8+5] = nData[i*3+2]
        }
    }

    // MARK: - MTKViewDelegate
    func mtkView(_ view: MTKView, drawableSizeWillChange size: CGSize) {
        engine_renderer_resize(UInt32(size.width), UInt32(size.height))
    }

    func draw(in view: MTKView) {
        let now = CACurrentMediaTime()
        var dt = Float(now - lastTime)
        lastTime = now
        if dt < 0.0 || dt > 0.25 { dt = 1.0/60.0 }

        engine_game_tick(dt)
        engine_mdl_animation_tick(dt)
        updateAnimatedMDLBuffer()

        guard let drawable = view.currentDrawable,
              let rpd      = view.currentRenderPassDescriptor,
              let cmd      = queue.makeCommandBuffer() else { return }

        rpd.colorAttachments[0].clearColor = MTLClearColor(red: 0.05, green: 0.05, blue: 0.08, alpha: 1.0)
        rpd.colorAttachments[0].loadAction = .clear

        engine_renderer_begin_frame()

        guard let enc = cmd.makeRenderCommandEncoder(descriptor: rpd) else { cmd.commit(); return }
        if let ds = depthState { enc.setDepthStencilState(ds) }

        // Camera
        var eye = [Float](repeating: 0, count: 3)
        var fwd = [Float](repeating: 0, count: 3)
        engine_player_get_eye(&eye)
        engine_player_get_forward(&fwd)

        let eyeV  = simd_float3(eye[0], eye[1], eye[2])
        let fwdV  = simd_normalize(simd_float3(fwd[0], fwd[1], fwd[2]))
        let target = eyeV + fwdV

        let viewMat = lookAtZUp(eye: eyeV, center: target, up: simd_float3(0, 0, 1))
        let projMat = perspective(fovY: 75 * .pi / 180,
                                   aspect: Float(view.drawableSize.width / view.drawableSize.height),
                                   near: 1.0, far: 50000.0)

        // ---- BSP ----
        if let pipeline = bspPipeline, let vb = vertexBuffer, let ib = indexBuffer, indexCount > 0 {
            enc.setRenderPipelineState(pipeline)

            var U = Uniforms(model: matrix_identity_float4x4,
                             view: viewMat,
                             proj: projMat,
                             lightDir: simd_normalize(simd_float3(0.3, 0.8, 0.5)),
                             pad0: 0,
                             baseColor: simd_float4(0.85, 0.9, 1.0, 1.0),
                             useTexture: hasTexture ? 1.0 : 0.0,
                             pad1: 0, pad2: 0, pad3: 0)

            enc.setVertexBuffer(vb, offset: 0, index: 0)
            enc.setVertexBytes(&U, length: MemoryLayout<Uniforms>.stride, index: 1)
            enc.setFragmentBytes(&U, length: MemoryLayout<Uniforms>.stride, index: 1)
            if let tex = atlasTexture, let ss = samplerState {
                enc.setFragmentTexture(tex, index: 0)
                enc.setFragmentSamplerState(ss, index: 0)
            }
            enc.drawIndexedPrimitives(type: .triangle,
                                      indexCount: indexCount,
                                      indexType: .uint32,
                                      indexBuffer: ib,
                                      indexBufferOffset: 0)
        }

        // ---- First-person viewmodel ----
        refreshViewmodelIfNeeded()
        drawViewmodel(enc, eye: eyeV, forward: fwdV, view: viewMat, proj: projMat)

        enc.endEncoding()
        engine_renderer_end_frame()
        cmd.present(drawable)
        cmd.commit()
    }

    // MARK: - Matrix helpers
    private func lookAtZUp(eye: simd_float3, center: simd_float3, up: simd_float3) -> simd_float4x4 {
        let f = simd_normalize(center - eye)
        let s = simd_normalize(simd_cross(f, up))
        let u = simd_cross(s, f)
        var m = matrix_identity_float4x4
        m.columns.0 = simd_float4( s.x,  u.x, -f.x, 0)
        m.columns.1 = simd_float4( s.y,  u.y, -f.y, 0)
        m.columns.2 = simd_float4( s.z,  u.z, -f.z, 0)
        m.columns.3 = simd_float4(-simd_dot(s, eye),
                                   -simd_dot(u, eye),
                                    simd_dot(f, eye), 1)
        return m
    }

    private func perspective(fovY: Float, aspect: Float, near: Float, far: Float) -> simd_float4x4 {
        let y = 1.0 / tanf(fovY * 0.5)
        let x = y / aspect
        let z = far / (near - far)
        var m = simd_float4x4(0)
        m.columns.0 = simd_float4(x, 0, 0, 0)
        m.columns.1 = simd_float4(0, y, 0, 0)
        m.columns.2 = simd_float4(0, 0, z, -1)
        m.columns.3 = simd_float4(0, 0, z * near, 0)
        return m
    }
}

// MARK: - SwiftUI wrapper
struct MetalView: UIViewRepresentable {
    func makeCoordinator() -> Coordinator { Coordinator() }

    func makeUIView(context: Context) -> MTKView {
        let v = MTKView()
        v.device = MTLCreateSystemDefaultDevice()
        v.colorPixelFormat = .bgra8Unorm
        v.depthStencilPixelFormat = .depth32Float
        v.clearColor = MTLClearColor(red: 0.05, green: 0.05, blue: 0.08, alpha: 1.0)
        v.preferredFramesPerSecond = 60
        v.enableSetNeedsDisplay = false
        v.isPaused = false
        let r = MetalRenderer(mtkView: v)
        context.coordinator.renderer = r
        DispatchQueue.main.async {
            r?.uploadMeshFromEngine()
        }
        return v
    }
    func updateUIView(_ uiView: MTKView, context: Context) {}
    final class Coordinator { var renderer: MetalRenderer? }
}

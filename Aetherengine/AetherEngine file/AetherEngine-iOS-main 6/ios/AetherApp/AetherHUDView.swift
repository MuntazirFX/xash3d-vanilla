// AetherHUDView.swift — AetherEngine-iOS · Clean-room.
// v0.9.0: rendered in-game HUD overlay driven by the engine runtime.

import SwiftUI
import Combine

struct AetherHUDView: View {
    private let refresh = Timer.publish(every: 1.0 / 30.0, on: .main, in: .common).autoconnect()

    @State private var health: Float = 0
    @State private var armor: Float = 0
    @State private var clip: Int = 0
    @State private var reserve: Int = 0
    @State private var weapon: String = ""
    @State private var flash: Float = 0
    @State private var message: String = ""
    @State private var messageTimer: Float = 0

    var body: some View {
        GeometryReader { geo in
            ZStack {
                // Classic FPS-style center crosshair. It stays independent from
                // touch controls so aiming remains readable on every aspect ratio.
                AetherCrosshair()
                    .frame(width: 30, height: 30)
                    .position(x: geo.size.width * 0.5, y: geo.size.height * 0.5)

                if messageTimer > 0 && !message.isEmpty {
                    Text(message)
                        .font(.system(size: 17, weight: .semibold, design: .monospaced))
                        .foregroundColor(.white)
                        .shadow(color: .black, radius: 2, x: 1, y: 1)
                        .position(x: geo.size.width * 0.5, y: geo.size.height * 0.72)
                }

                VStack {
                    Spacer()
                    HStack(alignment: .bottom) {
                        AetherStatusPanel(health: health, armor: armor)
                        Spacer()
                        AetherAmmoPanel(weapon: weapon, clip: clip, reserve: reserve)
                    }
                    .padding(.horizontal, max(18, geo.size.width * 0.035))
                    .padding(.bottom, max(18, geo.size.height * 0.035))
                }

                // Damage feedback is deliberately a transparent screen overlay,
                // not a custom menu or decorative UI.
                Rectangle()
                    .fill(Color.red)
                    .opacity(Double(min(max(flash, 0), 1)) * 0.22)
                    .allowsHitTesting(false)
            }
        }
        .allowsHitTesting(false)
        .onAppear { refreshHUD() }
        .onReceive(refresh) { _ in refreshHUD() }
    }

    private func refreshHUD() {
        health = engine_game_health()
        armor = engine_game_armor()
        clip = engine_game_weapon_clip()
        reserve = engine_game_weapon_reserve()
        weapon = String(cString: engine_game_weapon_name())
        flash = engine_game_damage_flash()
        message = String(cString: engine_game_hud_message())
        messageTimer = message.isEmpty ? 0 : 1
    }
}

private struct AetherCrosshair: View {
    var body: some View {
        ZStack {
            Rectangle().frame(width: 2, height: 9).offset(y: -8)
            Rectangle().frame(width: 2, height: 9).offset(y: 8)
            Rectangle().frame(width: 9, height: 2).offset(x: -8)
            Rectangle().frame(width: 9, height: 2).offset(x: 8)
        }
        .foregroundColor(.white)
        .shadow(color: .black, radius: 1)
    }
}

private struct AetherStatusPanel: View {
    let health: Float
    let armor: Float

    var body: some View {
        HStack(spacing: 14) {
            Text("HEALTH")
                .foregroundColor(.white.opacity(0.78))
            Text(String(max(0, Int(health.rounded()))))
                .font(.system(size: 27, weight: .bold, design: .monospaced))
                .foregroundColor(.white)

            Text("ARMOR")
                .foregroundColor(.white.opacity(0.78))
            Text(String(max(0, Int(armor.rounded()))))
                .font(.system(size: 27, weight: .bold, design: .monospaced))
                .foregroundColor(.white)
        }
        .font(.system(size: 12, weight: .bold, design: .monospaced))
        .padding(.horizontal, 12)
        .padding(.vertical, 7)
        .background(Color.black.opacity(0.48))
    }
}

private struct AetherAmmoPanel: View {
    let weapon: String
    let clip: Int
    let reserve: Int

    var body: some View {
        HStack(alignment: .bottom, spacing: 10) {
            Text(weapon.uppercased())
                .font(.system(size: 11, weight: .bold, design: .monospaced))
                .foregroundColor(.white.opacity(0.72))
            Text(String(max(0, clip)))
                .font(.system(size: 30, weight: .bold, design: .monospaced))
                .foregroundColor(.white)
            Text("/ \(max(0, reserve))")
                .font(.system(size: 17, weight: .bold, design: .monospaced))
                .foregroundColor(.white.opacity(0.82))
        }
        .padding(.horizontal, 12)
        .padding(.vertical, 7)
        .background(Color.black.opacity(0.48))
    }
}

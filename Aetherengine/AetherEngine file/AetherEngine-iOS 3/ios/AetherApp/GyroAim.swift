import Foundation
import Combine
import CoreMotion
final class GyroAim: ObservableObject {
    private let manager = CMMotionManager()
    @Published private(set) var delta = SIMD2<Float>(0,0)
    func start() { guard manager.isDeviceMotionAvailable else { return }; manager.deviceMotionUpdateInterval = 1.0/120.0; manager.startDeviceMotionUpdates() }
    func stop() { manager.stopDeviceMotionUpdates() }
}
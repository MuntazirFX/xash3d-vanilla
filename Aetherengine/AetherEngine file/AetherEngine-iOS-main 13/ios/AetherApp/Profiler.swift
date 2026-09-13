import Foundation
final class Profiler {
    private var startTime: UInt64 = 0
    func begin() { startTime = DispatchTime.now().uptimeNanoseconds }
    func end() -> Double { guard startTime != 0 else { return 0 }; return Double(DispatchTime.now().uptimeNanoseconds-startTime)/1_000_000.0 }
}
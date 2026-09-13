import Foundation
import UIKit
final class Haptics {
    static let shared = Haptics()
    private let impact = UIImpactFeedbackGenerator(style: .light)
    func prepare() { impact.prepare() }
    func fire() { impact.impactOccurred(); impact.prepare() }
}
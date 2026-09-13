import Foundation
import UIKit
final class KeyboardSupport: NSObject {
    weak var view: UIView?
    func attach(to view: UIView) { self.view = view; view.isMultipleTouchEnabled = true }
}
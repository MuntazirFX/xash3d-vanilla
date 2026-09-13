import Foundation
import Combine
#if canImport(GameController)
import GameController
#endif
final class GamepadSupport: ObservableObject {
    @Published private(set) var connected = false
    func start() {
#if canImport(GameController)
        connected = GCController.controllers().isEmpty == false
#endif
    }
}
import Foundation
#if canImport(GameKit)
import GameKit
#endif
final class GameCenterSupport {
    func authenticate() {
#if canImport(GameKit)
        GKLocalPlayer.local.authenticateHandler = { _, _ in }
#endif
    }
}
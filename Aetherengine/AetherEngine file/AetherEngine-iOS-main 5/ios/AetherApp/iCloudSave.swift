import Foundation
final class iCloudSave {
    private let store = NSUbiquitousKeyValueStore.default
    func write(_ data: Data, key: String) { store.set(data, forKey: key); store.synchronize() }
    func read(key: String) -> Data? { store.data(forKey: key) }
}
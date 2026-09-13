# AetherEngine Status — Gameplay Runtime Milestone

## Version

`0.1.1-gameplay`

## Implemented in this milestone

- Added `AetherGameRuntime` as the gameplay coordinator.
- Runtime owns player health/death/inventory and the active weapon set.
- Added crowbar and Glock to the runtime inventory.
- Added reserve 9mm ammo and reload handling for the Glock.
- Added weapon switching through the normalized input layer.
- Added a clean-room forward-cone hit test for runtime monster combat.
- Added Headcrab AI update and melee damage dispatch through the runtime.
- Added player death timer and respawn state handling.
- Connected BSP collision and parsed map entities to the runtime.
- Map player spawn entities are used when available; mesh center is the fallback.
- `monster_headcrab` BSP entities are instantiated into the gameplay runtime.
- iOS `MetalRenderer` now advances the gameplay runtime each frame.
- Added C bridge telemetry for game state, health, armor, weapon/ammo, and combat counters.
- Added a dedicated gameplay runtime test.

## Verification

Host C11 build with warnings-as-errors:

- `AetherEngineCore`: PASS
- `AetherGameRuntime`: PASS
- `100% tests passed`

This milestone does **not** claim full GoldSrc compatibility. Remaining work includes full weapon behavior, full NPC behaviors, complete entity semantics, animation playback, HUD rendering, VGUI, save/load integration, multiplayer, and the remaining world/rendering features.

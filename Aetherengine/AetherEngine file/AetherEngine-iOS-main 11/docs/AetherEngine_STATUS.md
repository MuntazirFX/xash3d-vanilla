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

## v0.2.0 — Gameplay Core Expansion

Implemented and verified:
- Central 14-weapon catalog with ammo metadata.
- Weapon ammo types and reserve state.
- Correct semi-auto trigger edge behavior in the runtime; automatic weapons may fire while held.
- Runtime HUD state (health, armor, clip, reserve, weapon id, damage flash).
- iOS bridge accessors for weapon name and HUD damage state.
- Gameplay regression test for weapon catalog and trigger semantics.

This milestone is still a clean-room gameplay foundation; it does not claim 1:1 GoldSrc behavior, proprietary Valve code, or bundled game assets.

## v0.2.1 — Gameplay Interaction Layer

Added:
- Central pickup representation and collection API.
- BSP entity seeding for common weapon, health, armor, suit, and ammo pickup entities.
- Proximity pickup handling through the existing Use action.
- Weapon pickup can become the active weapon.
- Runtime HUD pickup messages and pickup-count bridge accessor.
- MP5 and Egon marked as automatic fire modes.


## v0.3.1 — Combat Presentation Foundation
- Added `engine/client/presentation/AetherCombatPresentation.h/.c`.
- Combat events now drive weapon viewmodel selection, muzzle-flash timing, recoil, impact state, animation/audio event counters, and presentation text.
- Added C bridge accessors for viewmodel/effect/recoil presentation state.
- Resolved duplicate global C symbol names between HUD/menu/network modules.
- Added V0.3.1 regression test.

## v0.4.0 — MDL Runtime Foundation
- Added safe MDL sequence-descriptor parsing (`AetherMDLSequence`).
- Added runtime MDL animation controller (`AetherMDLAnimator`) with sequence selection, FPS timing, looping and normalized frame state.
- Added regression test for sequence parsing and animation timing.
- These APIs are groundwork for real GoldSrc viewmodel/world-model animation; they do not yet implement bone-pose decoding or final skinned rendering.

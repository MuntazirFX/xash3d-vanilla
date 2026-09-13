# AetherEngine-iOS

A brand-new, clean-room iOS game engine and application built from scratch.
**No XashFusion / xash3d-fwgs code or dependencies.**

## Target Games
1. Half-Life (`valve`)
2. Half-Life: Blue Shift (`bshift`)
3. Half-Life: Opposing Force (`gearbox`)
4. Counter-Strike 1.6 (`cstrike`)
5. Counter-Strike: Condition Zero (`czero`)

> **Note:** User must provide legally obtained game data. No copyrighted assets are bundled.

## Architecture
- `engine/core` – Foundation: types, arena, logging, engine runtime
- `engine/game` – Game registry & lifecycle manager

## Build Status
- [x] STEP 1: Core modules
- [ ] STEP 2: Verification
- [ ] STEP 3: Engine foundation
- [ ] STEP 4: iOS application
- [ ] STEP 5: 5-game configuration
- [ ] STEP 6: Touch/Input/Settings
- [ ] STEP 7: Renderer/Audio/Filesystem
- [ ] STEP 8: Build system
- [ ] STEP 9: GitHub Actions ARM64
- [ ] STEP 10: Complete verification

## Target
- iOS (iPhone / iPad)
- ARM64
- Unsigned IPA build supported


# AetherEngine — completed source expansion (2026-09-13)

This package expands the clean-room engine with a compilable gameplay foundation and
source modules for the planned systems. It does **not** contain Valve/Steam game
assets, proprietary Valve source, or game data.

## Implemented in this package

- Player health, armor, damage, death/respawn state and inventory
- Weapon core plus Crowbar and Glock firing/reload timing
- Monster core plus Headcrab behavior and damage
- Generic runtime state/update loop
- Physics body/AABB primitives
- HUD state model
- Animation timing core
- PVS bitset
- Save blob/file format
- Network state/packet primitives
- VGUI widget primitives
- Baseline source modules for the remaining planned subsystems
- iOS platform helper classes for gamepad, keyboard, mouse, gyro, haptics,
  iCloud key-value save, Game Center authentication and profiling
- CMake recursive source discovery so new engine C files are automatically built
- Host CTest smoke test
- CI verification updated to build and test the complete C engine tree

## Verification

Host build:

    cmake -S build -B /tmp/aether-build -DAETHER_BUILD_TESTS=ON
    cmake --build /tmp/aether-build --parallel 2
    ctest --test-dir /tmp/aether-build --output-on-failure

The clean-room implementation is intentionally independent of Xash3D-FWGS.
A fully Steam-compatible GoldSrc replacement is a much larger engineering task:
the newly added modules are the foundation/API layer and are not a claim that every
GoldSrc gameplay, AI, VGUI, networking, animation, rendering and asset behavior is
already 1:1 compatible.

The next engineering milestone is to connect the runtime to the existing BSP/entity/
collision/Metal path and implement the complete Half-Life single-player vertical
slice before expanding to the other four games and multiplayer.

## v0.4.0 — MDL animation/geometry foundation

The model pipeline now includes safe sequence-descriptor parsing and a runtime animation clock. MDL geometry extraction also decodes GoldSrc triangle strip/fan command streams with bounds checks instead of treating the command pointer as a flat triangle index array.

This remains a clean-room implementation and does not bundle Valve game data.

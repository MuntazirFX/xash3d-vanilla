# AetherEngine v0.7.0 — First-Person Viewmodel

This milestone connects the existing GoldSrc MDL/animation pipeline to the first-person camera path.

## Implemented

- `engine/client/view/AetherViewModel.h/.c`
  - active weapon → `models/v_*.mdl` mapping
  - camera-relative sway and movement bob
  - recoil contribution
  - stable per-weapon viewmodel state
- Game runtime owns a viewmodel state and updates it every frame.
- iOS bridge can refresh the active weapon viewmodel from the user's mounted game data.
- Metal renderer draws the active viewmodel in camera space after the BSP world.
- Viewmodel rendering uses a depth-always/no-depth-write state so the first-person weapon stays in front of the world.
- Viewmodel scale is derived from loaded MDL bounds to avoid extreme model sizes.
- Host regression test covers weapon path selection, state changes and finite offsets.

## Asset policy

No game assets are included. The engine requests the corresponding `models/v_*.mdl` path from the user's mounted game directory. Missing viewmodels are handled by keeping the viewmodel hidden.

## Validation

The host CMake build compiles every engine C source through recursive source discovery and the complete test suite passes.

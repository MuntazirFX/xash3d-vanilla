# AetherEngine implementation status

## What was changed

The existing source tree was preserved. Missing subsystem directories were added with
compilable implementations and common interfaces. The build was changed from a
hand-maintained source list to recursive CMake discovery.

## First playable target

The correct integration order is:

1. runtime
2. player health/damage/death/inventory
3. weapon base + crowbar + Glock
4. entity runtime
5. monster base + Headcrab
6. HUD
7. animation
8. world visibility/lighting
9. remaining weapons/NPCs/entities
10. save/load and transitions
11. classic menu/VGUI
12. multiplayer

## Verification

The host CMake build succeeds with all engine C sources, and the core smoke test
passes.

iOS compilation still requires an Apple/Xcode environment and should be run by the
existing macOS GitHub Actions workflow.

## Compatibility note

This source expansion is a clean-room engine foundation. It does not copy or bundle
Valve proprietary source code or copyrighted game data, and it does not by itself
constitute a complete 1:1 implementation of GoldSrc.

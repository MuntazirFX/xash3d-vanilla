# AetherEngine v1.4.0 — NPC Navigation Foundation

This milestone replaces the previous placeholder pathfinding/navmesh modules with a deterministic, allocation-free runtime graph and A* search.

## Implemented
- Fixed-capacity navigation graph (512 nodes, up to 6 outgoing links per node).
- Bidirectional helper for navigation links.
- Euclidean A* heuristic and weighted edge costs.
- Nearest navigation-node query.
- Route reconstruction with caller-provided output storage.
- Navigation wrapper suitable for NPC movement integration.
- Regression coverage for route selection, nearest-node queries and bidirectional connectivity.

## Scope
This is a navigation **foundation**, not a claim of full GoldSrc AI parity. Automatic BSP walkable-surface extraction, door-aware dynamic routing and full NPC schedules remain later milestones.

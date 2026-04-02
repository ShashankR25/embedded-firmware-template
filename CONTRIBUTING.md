# Contributing

## Principles
- Keep application code independent from direct register access.
- Prefer small pull requests with one clear purpose.
- Every behavioral change should include a test or a documented reason why testing is not feasible.
- Documentation must be updated when architecture, interfaces, or build flow changes.

## Branch Naming
- `feat/<short-topic>`
- `fix/<short-topic>`
- `docs/<short-topic>`
- `chore/<short-topic>`

## Commit Guidance
Use conventional-style commits where practical:
- `feat: add pwm output abstraction`
- `fix: clamp pid integral term`
- `docs: describe board bring-up flow`
- `chore: update toolchain version`

## Pull Request Checklist
- Project builds locally
- Formatting and lint checks pass
- Tests pass or limitation is documented
- Public interfaces reviewed for layering violations
- Documentation updated
- Hardware validation notes added when firmware behavior changes

## Code Review Rules
- Do not merge directly to `main`
- At least one reviewer approval required
- CI must pass before merge
- Squash merge preferred unless history structure matters

## Style
- C17 for firmware code
- Use `.clang-format` and `.clang-tidy`
- Keep modules cohesive and small
- Header files expose interfaces, source files own implementation details

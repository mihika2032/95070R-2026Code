## Repo overview

This repository is a VEX V5 C++ competition template using the VEX toolchain and a simple Makefile-based build. Key folders:
- [src](src) — implementation (.cpp) files (e.g. `main.cpp`, `functions.cpp`, `PID.cpp`, `autons.cpp`, `auton-selector.cpp`).
- [include](include) — public headers (e.g. `PID.h`, `robot-config.h`, `functions.h`, `autons.h`).
- [vex](vex) — VEX toolchain snippets: `mkenv.mk` and `mkrules.mk` (used by the top-level `makefile`).

Big picture
- The project is a single-process embedded control program for VEX V5 hardware. `main.cpp` wires up robot initialization, competition callbacks (auton/driver), and calls into modules in `src/`.
- Hardware and global configuration live in `robot-config.cpp` / `robot-config.h` — treat this as the single canonical place for motors/sensors.
- Autonomous behaviors are implemented in `autons.cpp` with selection handled by `auton-selector.cpp` / `auton-selector.h`.
- The PID controller is implemented across `include/PID.h` and `src/PID.cpp` — look here for control-loop semantics and tuning constants.

Build & workflow notes
- The top-level `makefile` includes `vex/mkenv.mk` and `vex/mkrules.mk` and expects VEX environment variables (`PROJECT`, `BUILD`) provided by those make fragments. Use `make` to build the full project when the VEX environment is available.
- For quick single-file builds in VS Code, the workspace includes a task labeled `C/C++: clang build active file` (see VS Code Tasks). This compiles a single source file with the clang toolchain referenced in the workspace tasks.
- Files to check when changing build behavior: [makefile](makefile) and [vex/mkenv.mk](vex/mkenv.mk).

Project conventions & patterns
- Header-only public API: public declarations live in `include/` and are included by `.cpp` files in `src/`.
- One-definition config: `robot-config.*` centralizes hardware objects (do not duplicate motor declarations across files).
- Naming: filenames mirror primary symbols (e.g., `PID.h` / `PID.cpp`, `autons.cpp` / `autons.h`). Keep that pairing when adding modules.
- No namespaces: code uses global scope for robot objects; avoid introducing namespaces unless refactoring across the whole repo.

Integration & external dependencies
- The code depends on the VEX C++ API (via `vex.h`) and the VEX toolchain make fragments in `vex/`.
- Avoid changing `vex/mkenv.mk` or `vex/mkrules.mk` unless you understand the VEX build system; these files supply compiler flags and required variables.

Examples & quick references
- To find the race between autonomous and driver code, inspect [src/main.cpp](src/main.cpp) which registers competition callbacks.
- PID loop structure and parameters: [include/PID.h](include/PID.h) and [src/PID.cpp](src/PID.cpp).
- Autonomous selection: [src/auton-selector.cpp](src/auton-selector.cpp) and [include/auton-selector.h](include/auton-selector.h).

How Copilot agents should behave here
- Preserve public APIs and header signatures when modifying code — upstream students rely on stable headers.
- Prefer minimal, focused changes. If a change touches build rules or `robot-config.*`, explain why and include a brief compatibility note.
- When adding new modules, add both `src/` and `include/` files following the existing naming conventions and update the `makefile` if new source patterns are not matched by existing wildcards.
- Do not assume tests exist; run local build commands before proposing code that changes build or linking behavior.

When you need more info
- If build fails, show full `make` or task output and the contents of `vex/mkrules.mk` — those files control compilation flags.
- Ask for clarification before refactoring `robot-config.*` or moving global objects into different modules.

Contact / context
- Short README is at [README.md](README.md). The original author/contact mentioned in README may have additional intent/context for design choices.

---
If you want, I can expand this with a short checklist to run before PRs (build, test on hardware, preserve API) or stitch in any existing CONTRIBUTING/AGENT notes you prefer.

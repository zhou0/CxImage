---
name: fix-windows-msvc-compile-errors
description: Workflow command scaffold for fix-windows-msvc-compile-errors in CxImage.
allowed_tools: ["Bash", "Read", "Write", "Grep", "Glob"]
---

# /fix-windows-msvc-compile-errors

Use this workflow when working on **fix-windows-msvc-compile-errors** in `CxImage`.

## Goal

Systematically resolve compile errors and warnings specific to Windows/MSVC by updating source files, headers, and build scripts to handle platform-specific issues.

## Common Files

- `CMakeLists.txt`
- `jasper/jpc/jpc_qmfb.c`
- `jasper/jpc/jpc_tsfb.c`
- `jasper/include/jasper/jas_config.h`
- `tiff/tif_config.h`
- `tiff/tif_dirinfo.c`

## Suggested Sequence

1. Understand the current state and failure mode before editing.
2. Make the smallest coherent change that satisfies the workflow goal.
3. Run the most relevant verification for touched files.
4. Summarize what changed and what still needs review.

## Typical Commit Signals

- Identify MSVC-specific compile errors and warnings.
- Guard GCC/Unix-specific code (e.g., unistd.h includes, compiler flags) with MSVC checks in headers and CMakeLists.txt.
- Update function signatures, casts, and types (e.g., pointer types, enum naming, narrowing conversions) to satisfy MSVC.
- Adjust usage of standard library functions (e.g., use _lfind and include search.h for MSVC).
- Repeat these changes across multiple modules (jasper, tiff, zlib, libpsd, CxImage/*, CMakeLists.txt).

## Notes

- Treat this as a scaffold, not a hard-coded script.
- Update the command if the workflow evolves materially.
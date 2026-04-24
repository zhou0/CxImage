```markdown
# CxImage Development Patterns

> Auto-generated skill from repository analysis

## Overview
This skill provides guidance for contributing to the CxImage codebase, a TypeScript project with no detected framework. It covers the project's coding conventions, common workflows (such as fixing Windows/MSVC compile errors and merging main into feature branches), and testing patterns. Use this skill to ensure consistency and efficiency when developing or maintaining CxImage.

## Coding Conventions

- **File Naming:**  
  Use camelCase for file names.  
  _Example:_  
  ```
  imageProcessor.ts
  ximaico.cpp
  ```

- **Import Style:**  
  Use relative imports.  
  _Example:_  
  ```typescript
  import { processImage } from './imageProcessor';
  ```

- **Export Style:**  
  Use named exports.  
  _Example:_  
  ```typescript
  export function processImage() { ... }
  export const IMAGE_TYPE = 'png';
  ```

- **Commit Messages:**  
  - Freeform style, no enforced prefixes.
  - Average length: ~58 characters.
  - Be descriptive about the changes.

## Workflows

### Fix Windows/MSVC Compile Errors
**Trigger:** When you need to make the codebase compile cleanly on Windows/MSVC, addressing errors and warnings due to platform differences.  
**Command:** `/fix-msvc-compile`

1. Identify MSVC-specific compile errors and warnings.
2. Guard GCC/Unix-specific code (e.g., `#include <unistd.h>`, compiler flags) with MSVC checks in headers and `CMakeLists.txt`.
3. Update function signatures, casts, and types (e.g., pointer types, enum naming, narrowing conversions) to satisfy MSVC.
4. Adjust usage of standard library functions (e.g., use `_lfind` and include `search.h` for MSVC).
5. Repeat these changes across relevant modules:
    - `jasper`, `tiff`, `zlib`, `libpsd`, `CxImage/*`, `CMakeLists.txt`
6. Commit changes with a detailed message listing all affected files and fixes.

_Example:_  
```cpp
#ifdef _MSC_VER
#include <search.h>
#else
#include <unistd.h>
#endif
```

### Merge Main into Feature Branch
**Trigger:** When you want to synchronize a feature or fix branch with the latest changes from `main` before continuing work or opening a PR.  
**Command:** `/merge-main`

1. Fetch and checkout your feature or fix branch.
2. Merge `main` into your branch:
    ```bash
    git fetch origin
    git checkout my-feature-branch
    git merge origin/main
    ```
3. Resolve any merge conflicts across project and configuration files.
4. Commit the merge with a standard message.
5. Continue development or testing.

## Testing Patterns

- **Framework:** Unknown (not specified in the codebase).
- **Test File Pattern:** Files named with `.test.` in their filename.
  _Example:_  
  ```
  imageProcessor.test.ts
  ```

- **General Practice:**  
  - Place tests alongside the modules they test.
  - Use descriptive test names and assertions.

## Commands

| Command            | Purpose                                                         |
|--------------------|-----------------------------------------------------------------|
| /fix-msvc-compile  | Systematically resolve Windows/MSVC compile errors and warnings |
| /merge-main        | Merge latest changes from main into a feature/fix branch        |
```
This skill introduces the core development patterns and conventions used in the CxImage TypeScript codebase. It covers file organization, code style, import/export practices, and testing patterns. By following these guidelines, contributors can maintain consistency and quality throughout the project.

## Coding Conventions

### File Naming
- Use **PascalCase** for all file names.
  - Example: `ImageProcessor.ts`, `ImageUtils.ts`

### Import Style
- Use **relative imports** for referencing other modules within the project.
  - Example:
    ```typescript
    import { resizeImage } from './ImageUtils';
    ```

### Export Style
- Use **named exports** for all exported functions, classes, or constants.
  - Example:
    ```typescript
    // ImageUtils.ts
    export function resizeImage(...) { ... }
    export const DEFAULT_SIZE = 256;
    ```

### Commit Messages
- Commit messages are freeform, with an average length of 37 characters.
  - No enforced prefix or pattern.

## Workflows

### Adding a New Feature
**Trigger:** When implementing a new feature or module
**Command:** `/add-feature`

1. Create a new file using PascalCase (e.g., `NewFeature.ts`).
2. Implement the feature using TypeScript.
3. Use relative imports for any dependencies.
4. Export functions or classes using named exports.
5. If applicable, add corresponding test files (see Testing Patterns).
6. Commit your changes with a clear, descriptive message.

### Refactoring Code
**Trigger:** When improving or restructuring existing code
**Command:** `/refactor`

1. Identify the code to refactor.
2. Update file names to PascalCase if necessary.
3. Ensure all imports remain relative.
4. Maintain named exports throughout.
5. Update or add tests as needed.
6. Commit changes with a descriptive message.

### Writing Tests
**Trigger:** When adding or updating tests
**Command:** `/write-test`

1. Create a test file matching the pattern `*.test.*` (e.g., `ImageUtils.test.ts`).
2. Write tests for the relevant functions or classes.
3. Use the project's preferred (unknown) testing framework.
4. Run tests to ensure correctness.
5. Commit test files with a clear message.

## Testing Patterns

- Test files follow the `*.test.*` naming convention (e.g., `ImageProcessor.test.ts`).
- The specific testing framework is not detected; follow existing patterns in the repository.
- Place test files alongside the files they test or in a dedicated test directory, as per project structure.

**Example:**
```typescript
// ImageUtils.test.ts
import { resizeImage } from './ImageUtils';

describe('resizeImage', () => {
  it('should resize an image to the given dimensions', () => {
    // test implementation
  });
});
```

## Commands
| Command        | Purpose                                    |
|----------------|--------------------------------------------|
| /add-feature   | Start the workflow for adding a new feature|
| /refactor      | Begin a code refactoring workflow          |
| /write-test    | Initiate writing or updating tests         |
```

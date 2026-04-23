```markdown
# CxImage Development Patterns

> Auto-generated skill from repository analysis

## Overview
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

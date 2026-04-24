---
name: merge-main-into-feature-branch
description: Workflow command scaffold for merge-main-into-feature-branch in CxImage.
allowed_tools: ["Bash", "Read", "Write", "Grep", "Glob"]
---

# /merge-main-into-feature-branch

Use this workflow when working on **merge-main-into-feature-branch** in `CxImage`.

## Goal

Merge the latest changes from the main branch into an ongoing feature/fix branch to keep it up to date and resolve conflicts.

## Common Files

- `.agents/skills/CxImage/SKILL.md`
- `.agents/skills/CxImage/agents/openai.yaml`
- `.claude/ecc-tools.json`
- `.claude/homunculus/instincts/inherited/CxImage-instincts.yaml`
- `.claude/identity.json`
- `.claude/skills/CxImage/SKILL.md`

## Suggested Sequence

1. Understand the current state and failure mode before editing.
2. Make the smallest coherent change that satisfies the workflow goal.
3. Run the most relevant verification for touched files.
4. Summarize what changed and what still needs review.

## Typical Commit Signals

- Fetch and checkout the feature/fix branch.
- Merge main into the branch.
- Resolve any merge conflicts across project and configuration files.
- Commit the merge with a standard message.
- Continue development or testing.

## Notes

- Treat this as a scaffold, not a hard-coded script.
- Update the command if the workflow evolves materially.
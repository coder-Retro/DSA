#!/usr/bin/env python3
"""
Recounts .cpp solution files under LeetCode/1.Easy, 2.Medium, 3.Hard and
rewrites the two places in LeetCode/README.md that display those counts:
  1. The directory-structure code block  ("1.Easy/       (113 problems)")
  2. The Documentation Status table       ("|  🟢 Easy   |   113    | ...")

Anchored on the fixed text (folder names / emoji + difficulty name), not on
line numbers, so it keeps working even if content is added above/below.
Only the count changes — everything else on each line (padding, the
Approach+TC/SC status column) is left untouched.
"""
import re
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[2]
LEETCODE_DIR = REPO_ROOT / "LeetCode"
README_PATH = LEETCODE_DIR / "README.md"

DIFFICULTIES = [
    ("1.Easy", "Easy"),
    ("2.Medium", "Medium"),
    ("3.Hard", "Hard"),
]


def count_solutions():
    counts = {}
    for folder, label in DIFFICULTIES:
        folder_path = LEETCODE_DIR / folder
        counts[label] = len(list(folder_path.glob("*.cpp"))) if folder_path.is_dir() else 0
    return counts


def update_tree_block(text, counts):
    for folder, label in DIFFICULTIES:
        # e.g. "├── 1.Easy/       (113 problems)" -> swap only the number
        pattern = re.compile(
            rf"({re.escape(folder)}/\s*\(\s*)\d+(\s*problems\))"
        )
        text = pattern.sub(rf"\g<1>{counts[label]}\g<2>", text)
    return text


def update_table(text, counts):
    lines = text.splitlines(keepends=True)
    for i, line in enumerate(lines):
        for _, label in DIFFICULTIES:
            if "|" not in line:
                continue
            # Only touch table rows that mention this difficulty name and
            # look like a table row (starts with a pipe).
            if re.search(rf"\b{label}\b", line) and line.lstrip().startswith("|"):
                cells = line.split("|")
                if len(cells) < 3:
                    continue
                # cells[0] = "" (before first pipe), cells[1] = Difficulty
                # cell, cells[2] = Problems cell -> replace its number,
                # keep the same total width for clean alignment.
                old_cell = cells[2]
                width = len(old_cell)
                new_cell = str(counts[label]).center(width)
                cells[2] = new_cell
                lines[i] = "|".join(cells)
    return "".join(lines)


def main():
    counts = count_solutions()
    original = README_PATH.read_text(encoding="utf-8")

    updated = update_tree_block(original, counts)
    updated = update_table(updated, counts)

    if updated != original:
        README_PATH.write_text(updated, encoding="utf-8")
        print(f"Updated counts: {counts}")
        return 0
    else:
        print(f"No changes needed. Counts already accurate: {counts}")
        return 0


if __name__ == "__main__":
    sys.exit(main())

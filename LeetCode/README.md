# 🧠 LeetCode

> **"Patterns get you to the whiteboard. Practice gets you through the interview."**

This section is where the patterns, data structures, and algorithms from the rest of the repo get put to the test against real problems. Every solution is self-contained: a `Use Case`, an `Approach`, and a documented `Time Complexity (TC)` / `Space Complexity (SC)`, so any file can be revised on its own without re-deriving the logic from scratch.

Problems are organized by difficulty, matching how they're solved chronologically — Easy first to build pattern recognition, then Medium and Hard to combine multiple patterns under pressure.

---

# 🎯 Learning Objectives

By working through this section, you should be able to:

* Translate a recognized pattern into working code under time pressure.
* Justify the time and space complexity of a solution, not just produce one.
* Compare brute-force vs. optimized approaches for the same problem.
* Build a personal reference of solved problems for quick revision before interviews.

---

# 📂 Directory Structure

```text
LeetCode/
├── 1.Easy/       (78 problems)
├── 2.Medium/     (37 problems)
├── 3.Hard/       (4 problems)
└── README.md
```

Each `.cpp` file is named after its LeetCode problem number (e.g. `1.cpp` → *Two Sum*) and follows this comment convention:

```cpp
/*
Approach: Name of the technique used
TC: O(...)
SC: O(...)
*/

class Solution {
public:
    // implementation
};
```

---

# 📊 Documentation Status

| Difficulty | Problems | Use Case + Approach + TC/SC |
| ---------- | :------: | :--------------------------: |
| 🟢 Easy    |    78    | ✅ Complete                   |
| 🟡 Medium  |    37    | 🔜 In Progress                |
| 🔴 Hard    |    4     | 🔜 In Progress                |

The goal is 100% documentation coverage across all three tiers — not just working solutions, but solutions that explain *why* they work and *what they cost*.

---

# 🧩 Difficulty Breakdown

## 🟢 Easy — Building Blocks

Focused on single-pattern problems: two pointers, hashing, basic recursion, and simple tree/linked-list traversal. The goal here is fluency — recognizing the pattern almost instantly and writing clean code for it.

## 🟡 Medium — Combining Patterns

Problems that typically require chaining two ideas together (e.g. sliding window + hashing, or two pointers + sorting), or applying a pattern to a less obvious data structure like a linked list or matrix.

## 🔴 Hard — Multi-Step Reasoning

Problems that need a non-obvious insight before a pattern even applies — often involving optimal substructure, multiple edge cases, or combining a data structure with an algorithm (e.g. heaps with sliding window).

---

# 💡 Tips for Success

* Don't jump to code — identify the pattern first (see `../Patterns/`).
* Write the brute-force approach mentally before optimizing; it makes the improvement in TC/SC obvious.
* After solving, revisit the `Approach` comment and ask: *could this be done in less time or space?*
* Revise Easy problems periodically — speed on fundamentals is what buys time for Medium/Hard in an actual interview.

---

# 🔗 Continue Learning

⬅️ Previous: **Patterns**

🏠 Back to: **Repository Home**

# ↩️ Backtracking Pattern

> **"Choose. Explore. Undo. Choose again."**

Backtracking is a problem-solving pattern that systematically explores all possible choices at a series of decision points, going as deep as possible along one path, and — upon hitting a dead end or exhausting that path — undoing the last choice and trying the next available one. It is essentially DFS over a "decision tree," where each node represents a partial solution and each edge represents a choice.

Backtracking builds directly on **Recursion**. Where plain recursion simply explores a single path forward, backtracking adds the critical extra step of *undoing* a choice's side effects before trying the next one — without that undo step, state from one branch would leak into sibling branches and corrupt them.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

- Recursion
- Function Call Stack
- Basic STL containers (`vector`)
- Time & Space Complexity basics

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

- Understand the "choose → explore → undo" structure of backtracking.
- Identify choice points and distinguish include/exclude decisions from loop-based sibling decisions.
- Write recursive functions that correctly pair every mutation with its undo.
- Recognize when a problem needs pruning (e.g. duplicate elimination, constraint checks) to avoid wasted work.
- Analyze the time and space complexity of a backtracking solution.

---

# 🧠 The Core Idea

Backtracking works by making a choice, recursing on the consequences of that choice, and then reversing the choice before trying the next one — so that every branch of the decision tree starts from a clean, correctly restored state.

## 1️⃣ Choice Point

A point in the recursion where more than one option is available (e.g. "include `nums[i]` in the current subset, or don't").

---

## 2️⃣ Explore

Having made a choice, recurse forward as if that choice were final — following it all the way to either a complete solution or a dead end.

---

## 3️⃣ Undo (Backtrack)

Before trying the next choice at the same choice point, reverse whatever mutation the previous choice made (e.g. `pop_back()` after a `push_back()`), so the state is exactly as it was before that choice — ready for a sibling branch to explore independently.

---

# 🔍 How to Recognize This Pattern

Backtracking is often useful when a problem involves:

- Exploring **all** possible combinations, permutations, or subsets
- Decision trees with **branching choices** at each step
- A need to abandon a partial solution early once it's known to be invalid (pruning)
- Problems phrased in terms of "find all ways to..." rather than "find the optimal way to..."

Common keywords include:

- All subsets / all combinations / all permutations
- Generate all valid...
- N-Queens / Sudoku-style placement
- Partition into...
- Word search / path finding with constraints

---

# 🧭 Choice-Point Structures

| Structure | Approach | Best Fit |
| --- | --- | --- |
| **Include/Exclude Recursion** | Two recursive calls per index: take it, or don't | Fixed-length input, one decision per element |
| **Loop-Based Recursion** | A `for` loop at each level chooses the *next* element to add | Variable-length results (subsets, combinations, permutations) |
| **Constraint-Pruned Backtracking** | Same as above, plus an early-exit check before recursing | Problems with validity rules (N-Queens, Sudoku) |

All three follow the same underlying choose → explore → undo shape — they differ only in *how* the next choice is selected, not in the core mechanic.

---

# 📂 Directory Structure

```text
Backtracking/
├── Backtracking.cpp
└── README.md
```

---

# 📄 File Overview

## `Backtracking.cpp`

This file introduces backtracking using the classic example of generating **all subsets of an array**, via include/exclude recursion.

### Concepts Covered

- Choice points expressed as two recursive branches (include vs. exclude)
- The `push_back()` / `pop_back()` pair as the "choose, then undo" mechanic
- Base case handling (`i == nums.size()`)
- Why every mutation before a recursive call needs a matching undo after it

```cpp
void subsets(const vector<int>& nums, vector<int>& ans, int i) {
    // Base Case, Subset Reached
    if (i == nums.size()) {
        for (int element : ans) cout << element << " ";
        cout << '\n';
        return;
    }
    // Include Current Value (Choice 1)
    ans.push_back(nums[i]);
    subsets(nums, ans, i + 1);
    // Exclude Current Value (Choice 2)
    ans.pop_back(); // Backtracking
    subsets(nums, ans, i + 1);
}
```

The example is intended to show the smallest possible backtracking skeleton — one choice point, two branches, one undo — before moving on to problems with pruning or loop-based choice points.

---

# 🧩 How Backtracking Works

Consider generating all subsets of `nums = [1, 2]`:

```text
subsets(ans=[], i=0)
  push_back(1)              → ans=[1]
  subsets(ans=[1], i=1)
    push_back(2)             → ans=[1,2]
    subsets(i=2) → base case → print "1 2"
    pop_back()               → ans=[1]
    subsets(i=2) → base case → print "1"
  pop_back()                 → ans=[]
  subsets(ans=[], i=1)
    push_back(2)             → ans=[2]
    subsets(i=2) → base case → print "2"
    pop_back()                → ans=[]
    subsets(i=2) → base case → print ""
```

Every `push_back` is matched by exactly one `pop_back` before the sibling branch runs — that pairing is what keeps each branch's state independent of the others.

---

# ⚡ Complexity Analysis

- **Time Complexity:** `O(n · 2ⁿ)` — there are `2ⁿ` leaves in the decision tree (each element is either included or excluded), and each leaf costs `O(n)` to print or copy out.
- **Space Complexity:** `O(n)` auxiliary — the recursion depth is at most `n`, and the `ans` vector holds at most `n` elements at any point in time (not counting output storage).

Pruned or constraint-checked variants can do better than the full `2ⁿ` in practice (e.g. skipping duplicate branches, or abandoning a partial solution early), but the worst-case tree size stays `O(2ⁿ)` unless the problem structure allows genuine pruning.

---

# 🌍 Real-World Applications

Backtracking is widely used in:

- Subsets / Subsets with Duplicates
- Combinations / Combination Sum
- Permutations / Permutations with Duplicates
- N-Queens
- Sudoku Solver
- Word Search (grid path with constraints)
- Palindrome Partitioning
- Generate Parentheses

---

# ⚠️ Common Mistakes

Avoid these common pitfalls:

- **Mismatched push/pop:** mutating state (e.g. `push_back`) inside a conditional branch, but undoing it (`pop_back`) unconditionally afterward — this either corrupts an outer frame's state or invokes undefined behavior on an empty container.
- **Hiding the "advance" step in a side effect** (e.g. `nums[i++]`) instead of passing `i + 1` explicitly — technically correct if evaluation order is understood, but fragile and easy to break on refactor.
- **Forgetting to undo shared/global state** — if a choice mutates something outside the local recursion (e.g. a class-level `unordered_set`), it must be un-mutated on the way back, or sibling branches will see stale exclusions from unrelated paths.
- **Deduplicating after generation instead of pruning during generation** — checking `if (result already in output) skip` at the leaves still pays the cost of generating every duplicate; skipping the *choice* that would create a duplicate sibling is asymptotically better.
- **Confusing loop-based "skip repeated choice" logic with include/exclude recursion** — the sibling-skip rule (`if (i > start && nums[i] == nums[i-1]) continue;`) depends on tracking *which choice was just made*, which a fixed-index include/exclude tree doesn't expose the same way a loop's `start` index does.

---

# 🎯 Suggested Practice

After understanding Backtracking, try implementing:

- Subsets (no duplicates)
- Subsets II (with duplicates)
- Combination Sum
- Permutations
- Permutations II (with duplicates)
- N-Queens
- Word Search
- Palindrome Partitioning

---

# 📝 Key Takeaways

- Backtracking is DFS over a decision tree: choose, explore, undo, choose again.
- Every state mutation made before a recursive call needs an exactly matching undo after it — this pairing is the actual "backtrack" step.
- Include/exclude recursion and loop-based recursion are both valid choice-point structures; pick the one that matches whether the problem has a fixed number of decisions or a variable-length set of next choices.
- Pruning during generation (skipping invalid or duplicate choices before recursing) is strictly better than generating everything and filtering afterward.
- Worst-case time is typically exponential (`O(2ⁿ)` or worse) since backtracking explores a full decision tree — the goal of pruning is to cut branches early, not to change the underlying complexity class in the worst case.

---

# 🔗 Related Patterns

⬅️ Previous: **Recursion**

➡️ Next: **DFS**

🏠 Back to: **Patterns**
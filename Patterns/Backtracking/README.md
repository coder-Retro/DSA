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
├── PracticeProblems/
├── Backtracking.cpp
└── README.md
```

---

# 📄 File Overview

## `Backtracking.cpp`

This file introduces backtracking using the classic **Rat in a Maze** problem: find all paths from the top-left cell to the bottom-right cell of an `n x n` grid, moving Up/Down/Right/Left through open cells (`1`), without revisiting a cell already on the current path.

### Concepts Covered

- A **loop-style choice point implemented as four sequential branches** — at each cell, try Up, then Down, then Right, then Left
- The `push_back()` / `pop_back()` pair on the path string as the "choose, then undo" mechanic for the *direction taken*
- The `m[r][c] = 1` / `m[r][c] = 0` pair as the "choose, then undo" mechanic for *marking/unmarking cells as visited* — the maze grid itself doubles as the visited-tracking structure, so there is no separate visited array to maintain
- Bounds/blocked/visited checks folded into a single early-return guard, acting as the pruning step before any state is mutated
- Base case handling (`r == n-1 && c == n-1`)
- Why every mutation before a recursive call needs a matching undo after it — here there are *two* mutations per choice point (the path character and the cell's value in `m`), and both need undoing

```cpp
class Backtracking {
    // Helper Data Members
    struct Dir { int r,c; char d; };
    const Dir dirs[4]={{1,0,'D'},{0,-1,'L'},{0,1,'R'},{-1,0,'U'}};
    // Backtracking Function
    void dfs(vector<vector<int>>& m,int r,int c,vector<string>& pS,string& p) {
        int n=m.size();
        if(r<0||c<0||r>=n||c>=n||!m[r][c]) return;
        if(r==n-1 && c==n-1) { pS.push_back(p); return; }
        m[r][c]=0; // Marking As Visited
        for(int i=0;i<4;i++) {
            p.push_back(dirs[i].d); // Choose Path
            dfs(m,r+dirs[i].r,c+dirs[i].c,pS,p); // Traverse Path
            p.pop_back(); // Backtracking
        }
        m[r][c]=1; // Marking as Un-visited
    }
public:
    vector<string> findPaths(vector<vector<int>>& maze) {
        int n=maze.size();
        if(!n||!maze[0][0]||!maze[n-1][n-1]) return {};
        vector<string> paths;
        string path;
        dfs(maze,0,0,paths,path);
        return paths;
    }
};
```

The example is intended to show a backtracking skeleton with **four sibling choices per node instead of two**, and **two parallel pieces of state to undo** (the path string and the maze cell's value) — a step up in complexity from a single include/exclude choice, before moving on to problems with pruning or loop-based choice points over an arbitrary number of options.

---

# 🧩 How Backtracking Works

Consider a tiny `2 x 2` maze where every cell is open:

```text
maze = {
  {1, 1},
  {1, 1}
}
```

Starting at `(0,0)`, trying to reach `(1,1)`:

```text
dfs(r=0, c=0, m=[[1,1],[1,1]], p="")
  m[0][0]=0                    → m=[[0,1],[1,1]]
  push_back('U')               → p="U"
  dfs(r=-1,c=0) → out of bounds → return immediately
  pop_back()                    → p=""
  push_back('D')                → p="D"
  dfs(r=1, c=0, m=[[0,1],[1,1]], p="D")
    m[1][0]=0                   → m=[[0,1],[0,1]]
    push_back('U')               → p="DU"
    dfs(r=0,c=0) → m[0][0]==0, already visited → return immediately
    pop_back()                    → p="D"
    push_back('D')                → p="DD"
    dfs(r=2,c=0) → out of bounds → return immediately
    pop_back()                    → p="D"
    push_back('R')                → p="DR"
    dfs(r=1,c=1) → base case (bottom-right) → save path "DR"
    pop_back()                    → p="D"
    push_back('L')                → p="DL"
    dfs(r=1,c=-1) → out of bounds → return immediately
    pop_back()                    → p="D"
    m[1][0]=1                    → m=[[0,1],[1,1]]
  pop_back()                    → p=""
  push_back('R')                 → p="R"
  dfs(r=0, c=1, m=[[0,1],[1,1]], p="R")
    m[0][1]=0                    → m=[[0,0],[1,1]]
    ... (Up out of bounds, Down reaches (1,1) → saves "RD", Right out of bounds, Left → m[0][0]==0, already visited)
    m[0][1]=1                    → m=[[0,1],[1,1]]
  pop_back()                    → p=""
  push_back('L')                 → p="L"
  dfs(r=0,c=-1) → out of bounds → return immediately
  pop_back()                    → p=""
  m[0][0]=1                     → m=[[1,1],[1,1]]
```

Two valid paths are found — `"DR"` and `"RD"` — and every `push_back`/`m[r][c]=0` is matched by exactly one `pop_back`/`m[r][c]=1` before the next sibling branch runs. That pairing is what keeps each branch's path string *and* the maze's visited-marking independent of the others, with `m` itself restored to its original all-open state once the whole search completes.

---

# ⚡ Complexity Analysis

- **Time Complexity:** `O(4^(n²))` in the worst case for an `n x n` grid — at every cell there are up to 4 choices (Up/Down/Right/Left), and the recursion can revisit any of the `n²` cells along different candidate paths before the `m[r][c]` check prunes it. In practice, marking cells as visited in `m` prevents any path from revisiting a cell, so the real branching factor is much smaller than 4 almost everywhere, but the bound is still exponential in the grid size.
- **Space Complexity:** `O(n)` auxiliary beyond the input — the maze `m` is mutated in place rather than copied into a separate visited structure, so it contributes no extra space; the recursion depth is at most `O(n²)` (one call per cell on the longest simple path), and the `p` path string grows to at most `O(n²)` characters at any point in time (not counting the stored output paths).

Reusing `m[r][c]` as the visited marker is what turns an otherwise-unbounded walk (which could loop forever between two cells) into a genuine backtracking search over *simple paths* — every cell can appear at most once on any single candidate path, and pruning happens the moment a move would revisit one. It also means the maze must be restored to its original state on the way back out, since the input itself is doubling as the algorithm's only visited-tracking structure.

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
- **Forgetting to undo shared/global state** — if a choice mutates something outside the local recursion (e.g. a class-level `unordered_set`, or an input grid reused as a visited marker), it must be un-mutated on the way back, or sibling branches will see stale exclusions from unrelated paths.
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
- N-Queens II
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
# 🧠 Dynamic Programming Pattern

> **"Solve it once, build on it forever."**

Dynamic Programming (DP) is an optimization technique that solves complex problems by breaking them into smaller overlapping subproblems, solving each subproblem only once, and reusing those results to construct the final answer — either by working top-down from the original problem or bottom-up from the base cases.

Dynamic Programming builds directly on **Memoization**. Where memoization caches results on top of a recursive solution (top-down), DP also includes an iterative, table-building alternative (bottom-up) — and, in many cases, a further-optimized version that drops the table entirely in favor of a handful of rolling variables.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

- Recursion
- Memoization
- Function Call Stack
- Basic STL containers (`vector`, `unordered_map`)
- Time & Space Complexity basics

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

- Understand the difference between top-down and bottom-up DP.
- Convert a recursive/memoized solution into an iterative tabulated one.
- Recognize when a DP table can be compressed into a fixed number of variables.
- Apply space optimization to reduce `O(n)` space down to `O(1)`.
- Analyze and compare time/space complexity across all three DP styles.

---

# 🧠 The Core Idea

Dynamic Programming works by starting from the base case(s) of a problem and building forward, step by step, toward the final answer — using previously computed values to compute the next one, instead of recalculating them from scratch.

## 1️⃣ Base Case

The smallest subproblem(s) whose answer is already known without further computation (e.g. `fibonacci(0) = 0`, `fibonacci(1) = 1`).

---

## 2️⃣ Building Forward

Starting from the base case(s), DP computes each subsequent value using only the results that came immediately before it. For Fibonacci, this means repeatedly computing `n3 = n1 + n2`, then shifting the window forward one step at a time.

---

## 3️⃣ Returning the Final State

Once the loop (or recursion) reaches the target input `n`, the most recently computed value already holds the answer — no extra combination step is needed at the end.

---

# 🔍 How to Recognize This Pattern

Dynamic Programming is often useful when a problem involves:

- Overlapping subproblems (the same smaller computation is needed multiple times)
- Optimal substructure (the answer can be built from answers to smaller versions of itself)
- Naive recursive solutions that are exponentially slow (e.g. `O(2^n)`)
- A need to trade memoization's recursive call stack for a faster, iterative equivalent

Common keywords include:

- Nth term
- Minimum / maximum cost or count
- Number of ways
- Optimal substructure
- Overlapping subproblems

---

# 🧭 The Three Styles of DP

| Style                         | Approach                      | Time   | Space                            |
| ----------------------------- | ----------------------------- | ------ | -------------------------------- |
| **Top-Down (Memoization)**    | Recursion + cache             | `O(n)` | `O(n)` cache + `O(n)` call stack |
| **Bottom-Up (Tabulation)**    | Iteration + full table        | `O(n)` | `O(n)` table                     |
| **Space-Optimized Bottom-Up** | Iteration + rolling variables | `O(n)` | `O(1)`                           |

All three are "correct" DP — they differ only in _how_ the subproblem results are stored and reused, not in the underlying idea.

---

# 📂 Directory Structure

```text
DynamicProgramming/
├── PracticeProblems/
├── DynamicProgramming.cpp
└── README.md
```

---

# 📄 File Overview

## `DynamicProgramming.cpp`

This file introduces the **space-optimized bottom-up** style of DP using the classic example of computing the **nth Fibonacci number**, iteratively and without recursion.

### Concepts Covered

- Base case handling (`n < 2`)
- Iterative bottom-up construction of the answer
- Replacing a full DP table with two rolling variables (`n1`, `n2`)
- Achieving `O(n)` time and `O(1)` space

The example is intended to show how a memoized recursive solution can be reshaped into a leaner, iterative one — and then compressed further.

---

# 🧩 How Dynamic Programming Works

Consider computing `fibonacci(5)` using **bottom-up tabulation** (a full array):

```text
table[0] = 0
table[1] = 1
table[2] = table[1] + table[0] = 1
table[3] = table[2] + table[1] = 2
table[4] = table[3] + table[2] = 3
table[5] = table[4] + table[3] = 5   ← answer
```

Every value is computed exactly once, in order, using only the values immediately before it — no recomputation, no recursive call stack.

**Space-optimized**, the same computation only needs the last two values at any point in time:

```text
n1=0, n2=1
i=2: n3 = 0+1 = 1   → n1=1, n2=1
i=3: n3 = 1+1 = 2   → n1=1, n2=2
i=4: n3 = 1+2 = 3   → n1=2, n2=3
i=5: n3 = 2+3 = 5   → n1=3, n2=5   ← n2 is now the answer
```

The full table was never needed — only a constant-size "window" of the two most recent results.

---

# ⚡ Complexity Analysis

- **Time Complexity:** `O(n)` — a single pass computes each value exactly once.
- **Space Complexity:** `O(1)` — only two rolling variables are kept, instead of an `O(n)` table or an `O(n)` recursive call stack.

This is a direct improvement over top-down memoization, which still carries `O(n)` space from either the cache or the recursion stack (or both).

---

# 🌍 Real-World Applications

Dynamic Programming is widely used in:

- Fibonacci / Tribonacci-style sequence problems
- Climbing Stairs / step-counting problems
- Coin Change / Combination counting problems
- Longest Common Subsequence / Longest Increasing Subsequence
- Knapsack-style optimization problems
- Grid path counting (Unique Paths)
- House Robber

---

# ⚠️ Common Mistakes

Avoid these common pitfalls:

- Forgetting to handle the base case(s) before entering the main loop.
- Mixing up the update order (e.g. overwriting `n1` before it's used to compute `n3`).
- Declaring a "rolling" variable inside the loop when it needs to persist across iterations (or vice versa, keeping unnecessary state outside the loop).
- Assuming space optimization is always possible — it only works when each new value depends on a small, fixed window of previous values, not the entire history.
- Ignoring integer overflow for large `n`, since Fibonacci (and similar sequences) grow exponentially even though the algorithm itself is linear.

---

# 🎯 Suggested Practice

After understanding Dynamic Programming, try implementing:

- Nth Fibonacci Number (Tabulated & Space-Optimized)
- Climbing Stairs
- Coin Change (Minimum Coins)
- Unique Paths in a Grid
- Longest Common Subsequence
- House Robber
- Word Break

---

# 📝 Key Takeaways

- DP builds the answer from the base case(s) upward, reusing previously computed values.
- There are three equally valid styles: Top-Down (Memoization), Bottom-Up (Tabulation), and Space-Optimized Bottom-Up.
- Space optimization is possible whenever a subproblem only depends on a fixed, small number of previous results.
- Converting a table-based DP solution into rolling variables can reduce `O(n)` space to `O(1)` without changing the time complexity.
- Always double-check for integer overflow when the values involved grow quickly, even though the algorithm itself is efficient.

---

# 🔗 Related Patterns

⬅️ Previous: **Memoization**

➡️ Next: **Greedy**

🏠 Back to: **Patterns**

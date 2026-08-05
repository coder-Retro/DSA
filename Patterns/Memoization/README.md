# 🧠 Memoization Pattern

> **"Don't compute what you've already computed — remember it instead."**

Memoization is an optimization technique used to speed up recursive algorithms by storing (caching) the results of expensive function calls, so that when the same inputs occur again, the cached result is returned instantly instead of being recalculated.

Memoization is closely tied to **Recursion**—it's typically layered on top of a plain recursive solution to eliminate redundant work. Understanding memoization is a key stepping stone toward **Dynamic Programming**, since memoization is essentially the "top-down" approach to DP.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* Recursion
* Function Call Stack
* Basic STL containers (`vector`, `unordered_map`)
* Time & Space Complexity basics

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand why naive recursion can be exponentially slow.
* Identify overlapping subproblems in a recursive solution.
* Apply a cache (`vector` or `unordered_map`) to store computed results.
* Choose the right cache structure based on input range.
* Recognize memoization as the foundation for Dynamic Programming.

---

# 🧠 The Core Idea

Memoization avoids recomputation by remembering results the function has already calculated.

## 1️⃣ Base Case

The condition that stops recursion — the smallest subproblem(s) whose answer is already known without further calls (e.g. `fibonacci(0) = 0`, `fibonacci(1) = 1`).

---

## 2️⃣ Cache Check

Before doing any real work, the function first checks whether the result for the current input already exists in the cache.

If it does, the cached value is returned immediately — no recomputation, no further recursive calls.

---

## 3️⃣ Recursive Case + Store

If the result isn't cached yet, the function computes it recursively as normal — but before returning, it **stores** the result in the cache so future calls with the same input are instant.

Each recursive call moves one step closer to the base case, just like plain recursion — the only difference is the cache layer wrapped around it.

---

# 🔍 How to Recognize This Pattern

Memoization is often useful when a problem involves:

* Recursion with **repeated/overlapping subproblems**
* The same function being called multiple times with identical arguments
* Naive recursive solutions that are exponentially slow (e.g. `O(2^n)`)
* Problems that can be broken into smaller, reusable subproblems

Common keywords include:

* Nth term
* Overlapping subproblems
* Optimal / minimum / maximum (recursive)
* Count the number of ways
* Recompute / redundant calculation

---

# 📂 Directory Structure

```text
Memoization/
├── Memoization.cpp
└── README.md
```

---

# 📄 File Overview

## `Memoization.cpp`

This file introduces memoization using the classic example of computing the **nth Fibonacci number**, contrasting it against plain (unoptimized) recursion.

### Concepts Covered

* Base case for recursion
* Cache lookup before computation
* Storing computed results (`cache[n] = result`)
* Choosing between `vector` and `unordered_map` as the cache

The example is intended to build intuition for *why* caching matters, not just how to write the syntax.

---

# 🧩 How Memoization Works

Consider computing `fibonacci(5)` **without** memoization:

```text
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   └── fib(1)
│   └── fib(2)   ← recomputed!
└── fib(3)       ← recomputed!
    ├── fib(2)   ← recomputed again!
    └── fib(1)   ← recomputed again!
```

Notice how `fib(3)` and `fib(2)` are calculated multiple times — this redundant work is what causes plain recursive Fibonacci to run in exponential time, `O(2^n)`.

**With memoization**, each unique subproblem is computed exactly once:

```text
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2) → compute & cache
│   │   └── fib(1) → base case
│   └── fib(2) → found in cache, return instantly
└── fib(3) → found in cache, return instantly
```

Once a result is cached, every future call with that same input becomes an `O(1)` lookup instead of a fresh recursive tree.

---

# 📚 The Cache

Every memoized call first checks the cache before doing any real computation:

```text
cache = { 2: 1, 3: 2, 4: 3 }   ← already computed

fib(4) → found in cache → return 3 instantly (no recursion)
fib(6) → not in cache → compute fib(5) + fib(4), then store fib(6)
```

Choosing the right cache structure matters:

| Cache Type       | Best For                                  |
|-------------------|--------------------------------------------|
| `vector<int>`     | Small, fixed, contiguous input ranges (e.g. `0` to `n`) |
| `unordered_map<int,int>` | Large, sparse, or variable/unpredictable input ranges |

---

# ⚡ Complexity Analysis

* **Time Complexity:** `O(n)` — each unique subproblem is computed once and cached; every repeat call is `O(1)`. This is a massive improvement over the `O(2^n)` of naive recursion.
* **Space Complexity:** `O(n)` — for the cache itself, plus `O(n)` for the recursive call stack.

Always compare the memoized complexity against the naive recursive complexity to appreciate *why* the pattern is worth applying.

---

# 🌍 Real-World Applications

Memoization is widely used in:

* Fibonacci / Tribonacci-style sequence problems
* Dynamic Programming (top-down approach)
* Grid path counting (Unique Paths)
* Longest Common Subsequence
* Coin Change / Combination counting problems
* Any recursive solution suffering from repeated overlapping calls

---

# ⚠️ Common Mistakes

Avoid these common pitfalls:

* Writing an incorrect base case, which either breaks correctness or skips recursion entirely (the base case must handle only the smallest inputs, not swallow the general case).
* Forgetting to check the cache *before* recomputing — defeats the entire purpose.
* Forgetting to *store* the result after computing it.
* Using a global/static cache across multiple independent calls without clearing it when needed.
* Choosing the wrong container (e.g. `vector` for a huge sparse range wastes memory; `unordered_map` for a small fixed range adds unnecessary overhead).

---

# 🎯 Suggested Practice

After understanding memoization, try implementing:

* Nth Fibonacci Number (Memoized)
* Climbing Stairs
* Coin Change (Minimum Coins)
* Unique Paths in a Grid
* Longest Common Subsequence
* House Robber
* Word Break

---

# 📝 Key Takeaways

* Memoization eliminates redundant recursive computation by caching results.
* Always check the cache **before** computing, and **store** the result after.
* `vector` suits small fixed ranges; `unordered_map` suits large/sparse ranges.
* Memoization turns exponential-time recursion into linear-time recursion for problems with overlapping subproblems.
* Memoization is the "top-down" gateway into Dynamic Programming.

---

# 🔗 Related Patterns

⬅️ Previous: **Recursion**

➡️ Next: **DynamicProgramming**

🏠 Back to: **Patterns**
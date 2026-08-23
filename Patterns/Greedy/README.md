# 🤑 Greedy Pattern

> **"Take the best option now, and hope it adds up to the best overall."**

A Greedy algorithm builds a solution piece by piece, always choosing whatever option looks best _at the current step_ — without reconsidering that choice later. Unlike Dynamic Programming, it never explores multiple branches or revisits a decision once it's made. It trusts that a sequence of locally optimal choices will produce a globally optimal (or acceptably good) result.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

- Arrays & Sorting
- Two Pointers
- Basic proof-by-contradiction / exchange argument intuition
- Time & Space Complexity basics

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

- Understand what makes a choice "greedy" versus "exhaustive."
- Recognize when a problem has the **greedy-choice property** (a locally optimal choice leads to a globally optimal solution).
- Distinguish problems that are solvable greedily from ones that actually require DP or backtracking.
- Combine Greedy with other techniques (e.g. Two Pointers, Sorting) to solve problems efficiently.
- Analyze time/space complexity of greedy solutions.

---

# 🧠 The Core Idea

Greedy algorithms work by selecting the locally best answer at every step, using only the information currently available — never backtracking to reconsider an earlier choice.

## 1️⃣ The Decision Point

At each step, the algorithm is faced with a small set of available options (e.g. which path to take, which coin to use, which interval to pick next).

---

## 2️⃣ The Greedy Choice

Among the available options, the algorithm picks whichever one looks best _right now_ — by some local metric (shortest, cheapest, largest, earliest, etc.) — and commits to it permanently.

---

## 3️⃣ Building the Final Answer

Repeating the greedy choice at every decision point, step by step, eventually produces the final answer — with no need to revisit or undo any earlier decision.

> ⚠️ This only works when the problem has the **greedy-choice property**. If an early "best" local choice can block a better global outcome, greedy will produce a wrong or suboptimal answer, and you need DP or backtracking instead.

---

# 🔍 How to Recognize This Pattern

Greedy is often useful when a problem involves:

- A sequence of independent decisions, each made once and never revisited
- An "optimal substructure" where the local best choice never conflicts with the global best choice
- Sorting the input first often exposes the greedy order (e.g. by start time, by ratio, by size)
- Problems phrased around scheduling, intervals, or resource allocation

Common keywords include:

- Maximum / minimum number of X
- Earliest / latest / soonest
- Non-overlapping intervals
- Minimum number of coins/jumps/platforms
- "At each step, choose the best available option"

---

# 🧭 Greedy vs. Dynamic Programming

| Aspect              | Greedy                                                   | Dynamic Programming                              |
| ------------------- | -------------------------------------------------------- | ------------------------------------------------ |
| **Decision-making** | Makes one choice and never revisits                      | Explores overlapping subproblems, reuses results |
| **Guarantee**       | Only correct if greedy-choice property holds             | Always correct if recurrence is correct          |
| **Speed**           | Usually faster (`O(n log n)` or `O(n)`)                  | Often slower due to table/cache overhead         |
| **Proof required**  | Needs justification (exchange argument / matroid theory) | Needs a correct recurrence relation              |

Both rely on **optimal substructure**, but only DP requires (and tolerates) **overlapping subproblems**. If subproblems overlap and a greedy choice can be proven wrong, DP is the safer tool.

---

# 📂 Directory Structure

```text
Greedy/
├── Greedy.cpp
└── README.md
```

---

# 📄 File Overview

## `Greedy.cpp`

This file introduces the Greedy pattern using the classic **Trapping Rain Water** problem (LeetCode Hard), which combines Greedy with the **Two Pointers** technique.

### Concepts Covered

- Tracking `leftMax` and `rightMax` as running "best so far" references
- Greedily advancing whichever pointer (`l` or `r`) points to the smaller boundary height
- Accumulating trapped water only when the current column is shorter than the max seen from its side
- Achieving `O(n)` time and `O(1)` space without a full DP table

---

# 🧩 How Greedy Works

Consider `trap(height)` with `height = [0,1,0,2,1,0,1,3,2,1,2,1]`:

```text
l=0, r=11, leftMax=0, rightMax=0, water=0

height[l]=0 < height[r]=1  → l-side is smaller, act on it
  height[0]=0 <= leftMax=0 → water += (0-0) = 0
  l++  → l=1

height[l]=1 < height[r]=1? → false (equal), act on r-side
  height[11]=1 <= rightMax=0? → false → rightMax=1
  r--  → r=10

... (process continues, always advancing the side with the smaller boundary) ...

Final: water = 6
```

At every step, the algorithm only looks at the two current boundary values — it never reconsiders a column once it's been passed. That "commit and move on" behavior is what makes this greedy: the locally smaller side is guaranteed to be bounded by its `max`, so the water above it can be computed immediately and correctly, without waiting to see the rest of the array.

---

# ⚡ Complexity Analysis

- **Time Complexity:** `O(n)` — each pointer moves inward once, so the array is traversed a single time.
- **Space Complexity:** `O(1)` — only a handful of scalar variables (`leftMax`, `rightMax`, `l`, `r`, `water`) are kept, no auxiliary array.

This is a direct improvement over a naive approach that precomputes `leftMax[]`/`rightMax[]` arrays, which would cost `O(n)` extra space.

---

# 🌍 Real-World Applications

Greedy algorithms are widely used in:

- Activity/Interval Scheduling (maximum non-overlapping meetings)
- Huffman Encoding (data compression)
- Minimum Spanning Tree (Kruskal's, Prim's)
- Dijkstra's Shortest Path (with a priority queue)
- Coin Change (only works greedily for certain coin systems, e.g. standard currency)
- Jump Game / Gas Station problems
- Trapping Rain Water

---

# ⚠️ Common Mistakes

Avoid these common pitfalls:

- Assuming greedy always works — always verify the greedy-choice property before trusting a greedy solution; some problems (e.g. 0/1 Knapsack, arbitrary Coin Change) need DP instead.
- Forgetting to sort the input first when the greedy order depends on it (e.g. sorting intervals by end time).
- Not handling empty or single-element inputs before entering the main loop — this can cause unsigned integer underflow (e.g. `size()-1` on an empty `vector`) or out-of-bounds access.
- Updating a "running max/min" tracker in the wrong order relative to using it (e.g. comparing before updating, or vice versa, inconsistently).
- Conflating "locally optimal" with "correct" — always double-check with a small counterexample before assuming a greedy strategy generalizes.

---

# 🎯 Suggested Practice

After understanding Greedy, try implementing:

- Trapping Rain Water
- Jump Game (I & II)
- Gas Station
- Non-overlapping Intervals
- Minimum Number of Platforms
- Task Scheduler
- Huffman Encoding

---

# 📝 Key Takeaways

- Greedy builds the answer step by step, committing to the locally best choice at each decision point.
- Correctness depends entirely on the problem having the greedy-choice property — always verify before assuming.
- Sorting the input by the right key is often the key step that makes a greedy strategy work.
- Greedy solutions are typically faster and simpler than DP, but only when applicable — when in doubt, look for a counterexample before trusting a greedy approach.
- Always guard against empty/edge-case inputs, especially when using unsigned sizes (`vector::size()`) in arithmetic.

---

# 🔗 Related Patterns

⬅️ Previous: **Dynamic Programming**

➡️ Next: **Backtracking**

🏠 Back to: **Patterns**

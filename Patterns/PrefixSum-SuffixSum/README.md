# ➕ Prefix Sum & Suffix Sum Pattern

> **"Precompute once, query forever."**

The **Prefix Sum** and **Suffix Sum** patterns are two of the most fundamental array techniques in Data Structures and Algorithms. Instead of recalculating the sum of a range every time it's needed, you build a helper array **once**, then answer range-sum queries instantly.

This pattern is especially useful for problems involving **range sum queries**, **subarray sums**, and **balancing left/right contributions** around an index.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* Arrays / Vectors
* Loops
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand the intuition behind prefix and suffix sums.
* Build a prefix sum array and a suffix sum array from scratch.
* Use them to answer range-sum queries in O(1).
* Recognize problems where this pattern applies.

---

# 🧠 The Core Idea

## Prefix Sum

`prefixSum[i]` stores the sum of all elements from the **start** of the array up to index `i`.

```text
arr:        1  2  3  4  5
prefixSum:  1  3  6  10 15
```

## Suffix Sum

`suffixSum[i]` stores the sum of all elements from index `i` to the **end** of the array — the mirror image of prefix sum.

```text
arr:        1  2  3   4   5
suffixSum:  15 14 12  9   5
```

Both are built in a single O(n) pass and, once built, let you answer "sum of range [i, j]" type queries without re-scanning the array.

---

# 🔍 How to Recognize This Pattern

Consider using Prefix/Suffix Sum if the problem mentions:

* Range Sum Query
* Subarray Sum Equals K
* Equilibrium / Pivot Index
* Product of Array Except Self (prefix × suffix combo)
* Sum to the left vs. sum to the right of an index

These keywords often indicate that precomputing cumulative sums will avoid repeated O(n) recalculation.

---

# 📂 Directory Structure

```text
PrefixSum/
├── prefixSum.cpp
├── suffixSum.cpp
└── README.md
```

---

# 📄 File Overview

## `prefixSum.cpp`

Builds `preSum[i]` = sum of `arr[0..i]`, computed left to right in a single pass.

## `suffixSum.cpp`

Builds `sufSum[i]` = sum of `arr[i..n-1]`, computed right to left and then reversed into forward index order.

---

# ⚡ Complexity Analysis

| Complexity | Value |
| ---------- | :---: |
| Time       |  O(n) |
| Space      |  O(n) |

Space can be reduced to O(1) if the sum is computed in-place, overwriting the original array instead of returning a new one.

---

# 🌍 Real-World Applications

The Prefix/Suffix Sum pattern is frequently used in:

* Range sum queries on static arrays
* Finding equilibrium/pivot points in an array
* Splitting problems that compare "left side" vs. "right side" of an index
* Building blocks for more advanced techniques (2D prefix sums, difference arrays)

---

# ⚠️ Common Mistakes

Beginners often:

* Confuse prefix sum with suffix sum direction.
* Forget to handle the first/last index as a base case.
* Rebuild the sum array inside a loop instead of computing it once.
* Assume O(1) space when a new array is actually being allocated (O(n)).

---

# 🎯 Suggested Practice

After understanding this pattern, try solving:

* Range Sum Query - Immutable
* Find Pivot Index
* Product of Array Except Self
* Subarray Sum Equals K
* Running Sum of 1d Array

---

# 📝 Key Takeaways

* Prefix sum accumulates from the left; suffix sum accumulates from the right.
* Both trade O(n) space for O(1) query time after an O(n) build.
* Together, they can solve problems that need both "sum to the left" and "sum to the right" of an index in one pass.

---

# 🔗 Related Patterns

⬅️ Previous: **Two Pointers**

🏠 Back to: **Patterns**

🏠 Repository Home
# 🪟 Sliding Window Pattern

> **"Don't restart from scratch — slide the window forward."**

The **Sliding Window** pattern is a technique used when working with contiguous subarrays or substrings of a certain size within a larger array. Instead of recalculating a value for every possible window from scratch — which leads to O(n·k) or worse — you maintain a running result and update it incrementally as the window slides, often reducing the time complexity to **O(n)**.

This pattern is especially useful for problems involving **fixed-size subarrays**, **maximum/minimum sum in a range**, and **substring problems with a size or condition constraint**.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* Arrays / Vectors
* Loops
* Two Pointers
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand the intuition behind the Sliding Window pattern.
* Distinguish fixed-size windows from variable-size windows.
* Implement a sliding window using two pointers.
* Analyze why this avoids redundant recomputation.
* Recognize problems where this pattern applies.

---

# 🧠 The Core Idea

Instead of recomputing a sum (or other value) for every window independently, you:

1. Compute the result for the **first window** once.
2. **Slide** the window forward by one step: subtract the element leaving on the left, add the element entering on the right.
3. Update your running answer as you go.

```text
arr:      1  1  1  3  3  3  2  2  2
window:  [1  1  1] 3  3  3  2  2  2   → sum = 3
             [1  1  3] 3  3  2  2  2   → sum = 5
                 [1  3  3] 3  2  2  2   → sum = 7
                     ...
```

Each step does O(1) work instead of re-summing the whole window, which is what makes this pattern O(n) overall instead of O(n·k).

---

# 🔍 How to Recognize This Pattern

Consider using Sliding Window if the problem mentions:

* Subarray / Substring of size **k**
* Maximum / Minimum Sum of a Fixed-Size Window
* Longest Substring With a Constraint
* Contiguous Sequence
* "At most k" or "exactly k" distinct elements

These keywords often indicate that a window sliding across the array can avoid recomputation.

---

# 📂 Directory Structure

```text
SlidingWindow/
├── SlidingWindow.cpp
└── README.md
```

---

# 📄 File Overview

## `SlidingWindow.cpp`

Implements `maxSubArraySumOfSizeK(arr, k)`, which finds the maximum sum of any contiguous subarray of size `k`.

### Concepts Covered

* Building the initial window
* Sliding the window one step at a time
* Maintaining a running sum instead of recalculating
* Tracking the best result seen so far

---

# ⚡ Complexity Analysis

| Complexity | Value |
| ---------- | :---: |
| Time       |  O(n) |
| Space      |  O(1) |

Only a fixed number of variables (`left`, `right`, `currSum`, `maxSum`) are used regardless of input size, so space stays constant.

---

# 🌍 Real-World Applications

The Sliding Window pattern is frequently used in:

* Network packet/data stream analysis (rolling averages)
* Fixed-size buffering
* Finding best/worst performing time ranges in data
* Text processing (longest substring problems)
* Technical interviews and competitive programming

---

# ⚠️ Common Mistakes

Beginners often:

* Initialize the running max to `0` instead of the first window's sum — fails silently on arrays with negative numbers.
* Forget to shrink the window from the left when sliding, causing the window size to grow indefinitely.
* Confuse fixed-size sliding window with variable-size sliding window (used for "longest substring satisfying X" type problems).
* Recompute the window sum from scratch on every slide instead of updating incrementally, losing the O(n) benefit.

---

# 🎯 Suggested Practice

After understanding this pattern, try solving:

* Maximum Sum Subarray of Size K
* Longest Substring Without Repeating Characters
* Minimum Size Subarray Sum
* Longest Substring with At Most K Distinct Characters
* Permutation in String

---

# 📝 Key Takeaways

* Sliding Window turns repeated full-window recomputation into incremental O(1) updates per step.
* Fixed-size windows (like this one) always maintain the same width as they slide.
* Always initialize your running result with the first window's value, not a default like `0`.

---

# 🔗 Related Patterns

⬅️ Previous: **Prefix Sum & Suffix Sum**

🏠 Back to: **Patterns**

🏠 Repository Home
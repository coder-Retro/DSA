# 🔎 Binary Search Pattern

> **"Cut the search space in half, every time."**

The **Binary Search** pattern is one of the most fundamental searching techniques in Data Structures and Algorithms. Instead of scanning an array element by element, it repeatedly narrows the search space by comparing the target against the middle element, achieving **O(log n)** time instead of the O(n) required by linear search.

This section also covers an important variation: binary search on a **rotated sorted array**, which requires first identifying which half of the array is currently sorted before deciding where the target could be.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* Arrays / Vectors
* Sorted Data
* Loops
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand the intuition behind Binary Search.
* Implement Binary Search on a plain sorted array.
* Recognize when Binary Search applies to a rotated sorted array.
* Handle duplicate values in a rotated sorted array correctly.
* Analyze why Binary Search achieves O(log n) time.

---

# 🧠 The Core Idea

Instead of checking every element, you maintain two bounds — `i` (left) and `j` (right) — and repeatedly check the middle element between them:

```text
arr:  1  2  3  4  5  6  7  8  9
              ↑
             mid
```

* If `nums[mid] == target`, you're done.
* If the target is smaller, discard the right half.
* If the target is larger, discard the left half.

Each comparison eliminates half of the remaining search space, which is what gives Binary Search its O(log n) time.

## Rotated Sorted Arrays

A rotated sorted array (e.g. `{4,5,6,7,0,1,2}`) isn't fully ascending anymore, so a plain `mid vs target` comparison doesn't work. Instead, the algorithm must:

1. Determine which half — left of `mid` or right of `mid` — is currently sorted.
2. Check if the target falls inside that sorted half's value range.
3. Search that half if it does; otherwise, search the other half.

If duplicates exist and `nums[i] == nums[mid] == nums[j]`, neither half can be trusted to be sorted, so both bounds shrink inward by one (`i++`, `j--`) instead.

---

# 🔍 How to Recognize This Pattern

Consider using Binary Search if the problem mentions:

* Sorted Array
* Rotated Sorted Array
* Find Target / Search Insert Position
* Find Minimum in Rotated Sorted Array
* "Given a sorted array..." (a strong signal on its own)

If the data is sorted — or was sorted before being rotated — Binary Search is almost always applicable.

---

# 📂 Directory Structure

```text
BinarySearch/
├── BinarySearch.cpp
└── README.md
```

---

# 📄 File Overview

## `BinarySearch.cpp`

Implements `searchRotatedSortedArr(nums, target)`, which finds the **first occurrence** of `target` in a sorted array that may have been rotated at an unknown pivot and may contain duplicate values.

### Concepts Covered

* Standard binary search bounds (`i`, `j`, `mid`)
* Handling rotation by identifying the sorted half
* Handling duplicates by shrinking both bounds when the sorted half is ambiguous
* Finding the leftmost occurrence once a match is found
* Guarding against empty input

---

# ⚡ Complexity Analysis

| Complexity | Value | Notes |
| ---------- | :---: | ----- |
| Time       | O(log n) | Degrades to O(n) worst case with many duplicate values (e.g. an all-equal array) |
| Space      |  O(1) | Only a fixed number of variables are used regardless of input size |

---

# 🌍 Real-World Applications

The Binary Search pattern is frequently used in:

* Searching large sorted datasets (databases, indexes)
* Finding insertion points to keep data sorted
* Version control bisection (finding the commit that introduced a bug)
* Searching rotated or circular sorted data (e.g. rotated logs, circular buffers)
* Technical interviews and competitive programming

---

# ⚠️ Common Mistakes

Beginners often:

* Move a pointer to `mid` instead of `mid + 1` / `mid - 1`, causing infinite loops.
* Forget to check `nums[mid] == target` before assuming a match, especially in rotated-array logic.
* Assume `nums[i] <= nums[mid]` always means the left half is sorted — this breaks when duplicates make the comparison ambiguous.
* Index into the array (`nums[0]`) before checking if it's empty, causing a crash.
* Assume finding **a** match is the same as finding the **first** occurrence when duplicates are present.

---

# 🎯 Suggested Practice

After understanding this pattern, try solving:

* Binary Search
* Search in Rotated Sorted Array
* Search in Rotated Sorted Array II (with duplicates)
* Find Minimum in Rotated Sorted Array
* Find First and Last Position of Element in Sorted Array

---

# 📝 Key Takeaways

* Binary Search only works on sorted (or rotated-but-originally-sorted) data.
* Always determine which half is sorted before deciding where to search in a rotated array.
* Duplicate values can make it impossible to tell which half is sorted — shrink both bounds when this happens.
* A pointer must always move past `mid` (`mid ± 1`), never to `mid` itself, or the loop may never terminate.

---

# 🔗 Related Patterns

⬅️ Previous: **Sliding Window**

🏠 Back to: **Patterns**

🏠 Repository Home
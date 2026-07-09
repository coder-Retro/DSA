# 👉 Two Pointers Pattern

> **"Process two elements simultaneously instead of repeatedly scanning the entire data structure."**

The **Two Pointers** pattern is one of the most fundamental and widely used techniques in Data Structures and Algorithms. Instead of using nested loops, this approach uses two pointers that move through a data structure in a coordinated manner, often reducing the time complexity from **O(n²)** to **O(n)**.

This pattern is especially useful for problems involving **sorted arrays**, **strings**, **linked lists**, and **palindrome checking**.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* Arrays
* Strings
* Loops
* Conditional Statements
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand the intuition behind the Two Pointers pattern.
* Identify problems where two pointers are appropriate.
* Implement common two-pointer solutions.
* Analyze the efficiency of the approach.
* Recognize situations where another pattern is more suitable.

---

# 🧠 The Core Idea

Instead of processing one element at a time—or comparing every pair of elements—you maintain **two pointers** that move according to the problem's requirements.

The pointers may:

* Move toward each other
* Move in the same direction
* Move at different speeds
* Represent different sections of the data structure

This simple idea eliminates unnecessary work and often leads to elegant, efficient solutions.

---

# 🔍 How to Recognize This Pattern

Consider using the Two Pointers pattern if the problem mentions:

* Sorted Array
* Pair Sum
* Target Sum
* Remove Duplicates
* Reverse an Array
* Reverse a String
* Palindrome
* Merge Two Sorted Arrays

These keywords often indicate that two coordinated pointers can solve the problem efficiently.

---

# 📂 Directory Structure

```text
TwoPointers/
├── TwoPointers.cpp
├── PracticeProblems/
└── README.md
```

---

# 📄 File Overview

## `TwoPointers.cpp`

This file introduces the fundamentals of the Two Pointers technique.

### Concepts Covered

* Initializing two pointers
* Pointer movement strategies
* Traversing arrays efficiently
* Comparing elements
* Eliminating unnecessary iterations

The examples provide a foundation for understanding how coordinated pointer movement leads to more efficient algorithms.

---

# 🚶 Common Pointer Strategies

## 1️⃣ Opposite Direction

```text
Left                    Right
 ↓                         ↓
1 2 3 4 5 6 7 8 9
```

Useful for:

* Pair Sum
* Palindrome Checking
* Container With Most Water

---

## 2️⃣ Same Direction

```text
Slow
 ↓
1 2 3 4 5 6
   ↑
 Fast
```

Useful for:

* Removing Duplicates
* Partitioning Arrays
* Filtering Elements

---

# ⚡ Complexity Analysis

| Complexity | Value |
| ---------- | :---: |
| Time       |  O(n) |
| Space      |  O(1) |

Compared to a nested-loop solution, the Two Pointers pattern often reduces quadratic time complexity to linear time.

---

# 🌍 Real-World Applications

The Two Pointers pattern is frequently used in:

* Searching sorted arrays
* Data compression
* Memory-efficient traversal
* String processing
* Text editors
* Competitive programming
* Technical interviews

---

# ⚠️ Common Mistakes

Beginners often:

* Move the wrong pointer after a comparison.
* Forget to handle edge cases.
* Use the technique on unsorted data when sorting is required.
* Create infinite loops by not updating pointers correctly.

Always verify the pointer movement logic before implementing the solution.

---

# 🎯 Suggested Practice

After understanding this pattern, try solving:

* Two Sum II
* Valid Palindrome
* Remove Duplicates from Sorted Array
* Squares of a Sorted Array
* Container With Most Water
* 3Sum
* Merge Sorted Arrays

---

# 📝 Key Takeaways

* Two Pointers reduces unnecessary comparisons.
* It is most effective on ordered or sequential data.
* Many O(n²) solutions can be optimized to O(n).
* Correct pointer movement is the key to success.

---

# 🔗 Related Patterns

⬅️ Previous: **Recursion**

➡️ Next: **Sliding Window**

🏠 Back to: **Patterns**

🏠 Repository Home

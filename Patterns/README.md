# 🧩 Problem Solving Patterns

> **"Don't memorize solutions. Recognize patterns."**

One of the biggest breakthroughs in learning Data Structures and Algorithms is realizing that most coding interview problems are **variations of a relatively small set of problem-solving patterns**.

Instead of memorizing hundreds of individual solutions, focus on identifying the underlying pattern. Once you recognize the pattern, the solution often becomes much more intuitive.

This section of the repository is dedicated to those reusable strategies. Each folder introduces a specific pattern, explains when to use it, and provides practical implementations to help you build pattern recognition skills.

---

# 🎯 Learning Objectives

By completing this section, you should be able to:

* Recognize common algorithmic patterns.
* Identify clues hidden in problem statements.
* Choose an efficient approach before writing code.
* Improve problem-solving speed and confidence.
* Build intuition for technical interviews and competitive programming.

---

# 🧠 Why Learn Patterns?

Many seemingly different problems can be solved using the same underlying idea.

For example:

* Finding the longest substring without repeating characters
* Maximum sum subarray of size *k*
* Minimum window substring

Although these problems look different, they are all based on the **Sliding Window** pattern.

Recognizing the pattern is often the hardest—and most valuable—part of solving the problem.

---

# 🗺️ Learning Roadmap

Follow the patterns in this recommended order:

```text
Recursion
     │
     ▼
Two Pointers
     │
     ▼
Sliding Window
     │
     ▼
Slow & Fast Pointers
     │
     ▼
Dynamic Programming
```

Each pattern builds upon the intuition developed in the previous one.

---

# 📂 Directory Structure

```text
Patterns/
├── Recursion/
├── TwoPointers/
├── SlidingWindow/
├── SlowAndFastPointers/
├── DynamicProgramming/
└── README.md
```

---

# 📚 Patterns Covered

## ➕ Prefix And Suffix Sum

A technique use to calculate the sum of elements from start or end to ith index and save it in an array, which can then be used as many times as needed. There are two forms of it:

* Prefix Sum
* Suffix Sum

---

## 👉 Two Pointers

A technique that uses two indices to efficiently process arrays, strings, or linked lists.

Common applications include:

* Pair Sum
* Removing Duplicates
* Merging Sorted Arrays
* Palindrome Checking

---

## 🐢🐇 Slow & Fast Pointers

Uses two pointers moving at different speeds to detect cycles or locate specific positions.

Common applications include:

* Cycle Detection
* Finding the Middle Node
* Happy Number
* Linked List Problems

---

## 🪟 Sliding Window

Processes contiguous portions of an array or string without repeatedly traversing the same elements.

Common applications include:

* Longest Substring
* Maximum Sum Subarray
* Minimum Window Substring

---

## Binary Search

Although binary search itself is an algorithm used mainly for search fast in large but sorted datasets. However, if we know that data is sorted then we can use binary search in problem solving as well.

* target < mid element (Search in left half)
* target > mid element (Search in right half)
* target = mid element (Target found)

---

## 🔁 Recursion

Learn how a function can solve a problem by calling itself on smaller subproblems.

Common applications include:

* Factorial
* Fibonacci
* Binary Trees
* Divide and Conquer
* Backtracking

---

# 🔍 Pattern Recognition Cheat Sheet

| If the problem mentions...                | Consider...          |
| ----------------------------------------- | -------------------- |
| Pair, Sorted Array, Palindrome            | Two Pointers         |
| Contiguous Subarray / Substring           | Sliding Window       |
| Cycle, Middle Node, Repeating Sequence    | Slow & Fast Pointers |
| Recursive Definition, Tree Traversal      | Recursion            |

---

# 💡 Tips for Success

* Read the problem carefully before coding.
* Look for keywords that hint at a pattern.
* Focus on understanding *why* the pattern works.
* Practice variations of the same pattern.
* Analyze time and space complexity after solving each problem.

---

# 🚀 Recommended Learning Strategy

For each pattern:

1. Read the README.
2. Study the provided implementation.
3. Dry-run the algorithm by hand.
4. Solve the included practice problems.
5. Attempt similar problems without looking at the solution.

Consistency is more valuable than memorizing isolated solutions.

---

# 🌍 Why This Matters

Pattern recognition is one of the most important skills for:

* Technical Interviews
* Competitive Programming
* Online Assessments
* Software Engineering
* Efficient Problem Solving

The more patterns you master, the easier it becomes to solve unfamiliar problems with confidence.

---

# 🔗 Continue Learning

⬅️ Previous: **Algorithms**

➡️ Next: **Recursion**

🏠 Back to: **Repository Home**

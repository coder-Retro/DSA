# 🔁 Recursion Pattern

> **"A function that solves a problem by solving smaller instances of the same problem."**

Recursion is one of the most elegant and powerful techniques in computer science. Instead of using loops, a recursive function repeatedly calls itself with a smaller input until it reaches a condition that stops the recursion.

Many advanced algorithms—including **Divide & Conquer**, **Backtracking**, **Tree Traversals**, and **Dynamic Programming**—are built upon recursion. Mastering this concept is essential for becoming proficient in Data Structures and Algorithms.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* Functions
* Parameters & Return Values
* Loops
* Variables
* Basic Stack Concept

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand how recursive function calls work.
* Identify the two essential parts of every recursive solution.
* Visualize the function call stack.
* Convert simple iterative solutions into recursive ones.
* Solve classic recursion problems with confidence.

---

# 🧠 The Core Idea

Every recursive algorithm consists of two essential components:

## 1️⃣ Base Case

The condition that stops further recursive calls.

Without a base case, recursion continues indefinitely, eventually causing a **Stack Overflow**.

---

## 2️⃣ Recursive Case

The function calls itself with a **smaller** or **simpler** version of the original problem.

Each recursive call moves one step closer to the base case.

---

# 🔍 How to Recognize This Pattern

Recursion is often useful when a problem involves:

* Repeating the same task on a smaller input
* Trees
* Divide & Conquer
* Mathematical definitions
* Backtracking
* Nested structures

Common keywords include:

* Tree
* Nested
* Subproblem
* Divide
* Explore all possibilities
* Factorial
* Fibonacci

---

# 📂 Directory Structure

```text
Recursion/
├── Recursion.cpp
├── PracticeProblems/
└── README.md
```

---

# 📄 File Overview

## `Recursion.cpp`

This file introduces the fundamentals of recursion and demonstrates how recursive functions execute through repeated self-calls.

### Concepts Covered

* Recursive functions
* Base cases
* Recursive cases
* Function call stack
* Breaking a problem into smaller subproblems

The examples are intended to build intuition rather than simply demonstrate syntax.

---

# 🧩 How Recursion Works

Consider the factorial function:

```cpp
factorial(4)
```

Execution flow:

```text
factorial(4)
    │
    ▼
factorial(3)
    │
    ▼
factorial(2)
    │
    ▼
factorial(1)
    │
    ▼
Return 1
    ▲
    │
Return 2
    ▲
    │
Return 6
    ▲
    │
Return 24
```

Each function call is placed on the **Call Stack** until the base case is reached.

---

# 📚 The Function Call Stack

Every recursive call is stored in memory until it finishes executing.

```text
Top of Stack
───────────────
factorial(1)
factorial(2)
factorial(3)
factorial(4)
───────────────
Bottom of Stack
```

Once the base case is reached, the stack begins to **unwind**, returning values one by one.

---

# ⚡ Complexity Analysis

The complexity of recursion depends on the number of recursive calls.

Always analyze:

* **Time Complexity**
* **Space Complexity** (including the call stack)

Recursive solutions often require additional memory because each function call occupies stack space.

---

# 🌍 Real-World Applications

Recursion is widely used in:

* Binary Tree Traversals
* Graph Traversals (DFS)
* Merge Sort
* Quick Sort
* Backtracking
* Dynamic Programming
* File System Traversal
* Expression Parsing

---

# ⚠️ Common Mistakes

Avoid these common pitfalls:

* Forgetting the base case.
* Creating recursive calls that don't reduce the problem size.
* Ignoring stack overflow risks.
* Using recursion when iteration is simpler.
* Not analyzing space complexity.

---

# 🎯 Suggested Practice

After understanding recursion, try implementing:

* Factorial
* Fibonacci Sequence
* Sum of an Array
* Reverse a String
* Binary Search (Recursive)
* Tower of Hanoi
* Generate Subsets
* Generate Permutations

---

# 📝 Key Takeaways

* Every recursive function needs a **Base Case** and a **Recursive Case**.
* Recursive problems are solved by reducing them into smaller subproblems.
* Function calls are managed using the **Call Stack**.
* Recursion is the foundation for many advanced DSA techniques.

---

# 🔗 Related Patterns

⬅️ Previous: **Slow & Fast Pointers**

➡️ Next: **Dynamic Programming**

🏠 Back to: **Patterns**

🏠 Repository Home

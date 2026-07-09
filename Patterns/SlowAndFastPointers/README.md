# 🐢🐇 Slow & Fast Pointers Pattern

> **"When two pointers move at different speeds, they reveal hidden structure."**

The **Slow & Fast Pointers** pattern—also known as **Floyd's Cycle Detection Algorithm** or the **Tortoise and Hare Algorithm**—uses two pointers moving at different speeds through the same data structure.

This elegant technique allows us to detect cycles, locate the middle of a linked list, and solve several interview problems in **linear time using constant extra space**.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* Pointers
* Linked Lists
* Loops
* Basic Time Complexity
* Two Pointers Pattern

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand why two pointers move at different speeds.
* Detect cycles efficiently.
* Find the middle node of a linked list.
* Identify the starting point of a cycle.
* Recognize interview problems that use this pattern.

---

# 🧠 The Core Idea

Maintain two pointers:

* 🐢 **Slow Pointer** → moves **one step** at a time.
* 🐇 **Fast Pointer** → moves **two steps** at a time.

If a cycle exists, the fast pointer will eventually "lap" the slow pointer, causing both pointers to meet.

If no cycle exists, the fast pointer will eventually reach the end of the data structure.

---

# 🔍 How to Recognize This Pattern

This pattern is a great fit when the problem mentions:

* Linked List
* Cycle Detection
* Loop
* Middle Node
* Happy Number
* Circular Array
* Repeated Sequence

These clues often indicate that moving two pointers at different speeds can solve the problem efficiently.

---

# 📂 Directory Structure

```text
SlowAndFastPointers/
├── SlowAndFastPointers.cpp
└── README.md
```

---

# 📄 File Overview

## `SlowAndFastPointers.cpp`

This file demonstrates the fundamentals of the Slow & Fast Pointers technique.

### Concepts Covered

* Initializing slow and fast pointers
* Moving pointers at different speeds
* Detecting cycles
* Understanding pointer convergence
* Efficient traversal without additional memory

The implementation illustrates how this simple strategy can solve problems that might otherwise require extra data structures.

---

# 🐢🐇 Visual Walkthrough

Imagine the following linked list:

```text
1 → 2 → 3 → 4 → 5
          ↑     ↓
          ← ← ←
```

### Step 1

```text
Slow → 1
Fast → 1
```

### Step 2

```text
Slow → 2
Fast → 3
```

### Step 3

```text
Slow → 3
Fast → 5
```

### Step 4

```text
Slow → 4
Fast → 4

✔ Both pointers meet.
Cycle detected.
```

---

# ⚡ Complexity Analysis

| Complexity | Value |
| ---------- | :---: |
| Time       |  O(n) |
| Space      |  O(1) |

Only one traversal is required, and no additional data structures are needed.

---

# 🌍 Real-World Applications

The Slow & Fast Pointers pattern is commonly used in:

* Linked List Cycle Detection
* Finding the Middle of a Linked List
* Detecting Infinite Loops
* Happy Number Problems
* Circular Array Cycle Detection
* Memory-efficient traversal algorithms

---

# ⚠️ Common Mistakes

Be careful to avoid these common errors:

* Forgetting to check if the fast pointer or `fast->next` is `nullptr`.
* Advancing both pointers at the same speed.
* Assuming every linked list contains a cycle.
* Dereferencing a null pointer when the list is empty.

Always perform null checks before moving the fast pointer.

---

# 🎯 Suggested Practice

After understanding this pattern, try solving:

* Linked List Cycle
* Linked List Cycle II
* Middle of the Linked List
* Happy Number
* Circular Array Loop
* Find the Duplicate Number

These problems reinforce the core ideas behind the pattern.

---

# 📝 Key Takeaways

* The slow pointer advances one step at a time.
* The fast pointer advances two steps at a time.
* If the pointers meet, a cycle exists.
* The technique runs in **O(n)** time using **O(1)** extra space.
* It is one of the most elegant and frequently tested linked-list patterns.

---

# 🔗 Related Patterns

⬅️ Previous: **Sliding Window**

➡️ Next: **Dynamic Programming**

🏠 Back to: **Patterns**

🏠 Repository Home

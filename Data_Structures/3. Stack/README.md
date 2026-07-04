# 📚 Implementing a Stack

> **"A stack is a Last-In, First-Out (LIFO) data structure where the most recently inserted element is always the first one to be removed."**

A stack is one of the simplest yet most widely used abstract data types in computer science. Although its interface is straightforward, there are multiple ways to implement it, each with its own advantages and trade-offs.

This chapter explores two common implementations:

* **Vector-Based Stack** – Uses a dynamic array internally.
* **Linked List-Based Stack** – Uses dynamically allocated nodes connected by pointers.

By implementing both versions, you'll understand how the choice of underlying data structure affects performance, memory usage, and implementation complexity.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

* Dynamic Arrays (Vectors)
* Linked Lists
* Pointers
* Classes & Objects
* Dynamic Memory Allocation
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand the LIFO principle.
* Implement a stack using a dynamic array.
* Implement a stack using a linked list.
* Compare both implementations.
* Analyze their performance and memory trade-offs.
* Choose the appropriate implementation for different scenarios.

---

# 📂 Directory Structure

```text
Stack/
├── VectorStyleStack/
│   └── Stack.cpp
├── ListStyleStack/
│   └── Stack.cpp
└── README.md
```

---

# 🧠 The Core Idea

Stacks allow insertion and removal from **only one end**, called the **Top**.

```text
Push Operations

Top
 │
 ▼
+-----+
| 30  |
+-----+
| 20  |
+-----+
| 10  |
+-----+
```

The last element inserted becomes the first element removed.

This behavior is known as **Last In, First Out (LIFO)**.

---

# ⚙️ Supported Operations

A typical stack implementation supports:

* `push()`
* `pop()`
* `top()` / `peek()`
* `isEmpty()`
* `size()`
* `clear()`

These operations remain the same regardless of the underlying implementation.

---

# 🏗️ Implementation 1 — Vector-Based Stack

A vector-based stack stores elements in a dynamic array.

```text
Bottom                     Top
+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |
+----+----+----+----+----+
```

### How It Works

* `push()` appends an element to the end of the vector.
* `pop()` removes the last element.
* `top()` returns the last element without removing it.

Because all operations occur at the end of the vector, they are highly efficient.

### Advantages

* Excellent cache locality.
* Simple implementation.
* Fast random access (if needed internally).
* Minimal pointer manipulation.

### Limitations

* May trigger memory reallocation when capacity is exceeded.
* Insertions and deletions are efficient only at the top.

---

# 🔗 Implementation 2 — Linked List-Based Stack

A linked list implementation stores each element as a node.

```text
Top
 │
 ▼
+-------+------+     +-------+------+     +-------+------+
|  30   | Next | --> |  20   | Next | --> |  10   | NULL |
+-------+------+     +-------+------+     +-------+------+
```

The `head` pointer always represents the top of the stack.

### How It Works

* `push()` creates a new node and places it at the front.
* `pop()` removes the head node.
* `top()` returns the value stored in the head node.

### Advantages

* No resizing or reallocation.
* Constant-time insertions and deletions.
* Grows until available memory is exhausted.

### Limitations

* Extra memory is required for pointers.
* Poorer cache locality compared to vectors.
* More complex memory management.

---

# 📊 Complexity Comparison

| Operation    | Vector-Based | Linked List-Based |
| ------------ | :----------: | :---------------: |
| Push         |     O(1)*    |        O(1)       |
| Pop          |     O(1)     |        O(1)       |
| Top          |     O(1)     |        O(1)       |
| Size         |     O(1)     |        O(1)       |
| Extra Memory |      Low     |       Higher      |

> ***** `push()` is **amortized O(1)** because vector resizing occurs only occasionally.

---

# 🧠 Which Implementation Should You Choose?

| Requirement                                 | Recommended Implementation |
| ------------------------------------------- | -------------------------- |
| Better cache performance                    | ✅ Vector                   |
| Unlimited dynamic growth                    | ✅ Linked List              |
| Simpler implementation                      | ✅ Vector                   |
| Frequent memory reallocations are a concern | ✅ Linked List              |
| Lower memory overhead                       | ✅ Vector                   |

For most applications, a vector-based implementation offers excellent performance due to contiguous memory. A linked list implementation becomes useful when avoiding reallocations or when integrating with other node-based structures.

---

# 🌍 Real-World Applications

Stacks are used extensively in:

* Function Call Stack
* Undo / Redo Systems
* Browser History
* Expression Evaluation
* Parentheses Matching
* Depth-First Search (DFS)
* Syntax Parsing
* Backtracking Algorithms

---

# ⚠️ Common Implementation Mistakes

When implementing a stack, beginners often:

* Allow `pop()` on an empty stack.
* Forget to update the top pointer after `pop()`.
* Leak memory in linked list implementations.
* Return invalid references after removing an element.
* Ignore stack underflow conditions.

Always validate that the stack is not empty before accessing the top element.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

* Copy Constructor
* Move Constructor
* Assignment Operator
* Reverse a Stack
* Sort a Stack
* Stack using Two Queues
* Minimum Stack (`getMin()` in O(1))
* Expression Evaluator

These exercises strengthen your understanding of stack behavior and implementation techniques.

---

# 📝 Key Takeaways

* A stack follows the **Last-In, First-Out (LIFO)** principle.
* The same abstract data type can be implemented using different underlying data structures.
* Vector-based stacks provide excellent cache performance and low memory overhead.
* Linked list-based stacks eliminate resizing but require additional memory for node pointers.
* Understanding multiple implementations helps you choose the right solution for different problems.

---

# 🔗 Related Implementations

⬅️ **Linked List** — Provides the node-based foundation for one stack implementation.

➡️ **Queue** — Similar interface but follows the **First-In, First-Out (FIFO)** principle.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home

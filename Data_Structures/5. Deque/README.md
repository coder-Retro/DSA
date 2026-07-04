# ↔️ Implementing a Double-Ended Queue (Deque)

> **"A deque combines the flexibility of both a stack and a queue by allowing insertion and deletion from both the front and the rear."**

A **Deque** (pronounced *deck*) is a linear data structure that generalizes both **Stacks** and **Queues**. Unlike a queue, which inserts at one end and removes from the other, a deque allows operations at **both ends**.

Because of this flexibility, a deque can efficiently behave as:

* A **Stack (LIFO)**
* A **Queue (FIFO)**
* A true **Double-Ended Queue**

This chapter explores both STL-style and custom implementations, providing insight into how a deque manages elements internally.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

* Vectors (Dynamic Arrays)
* Linked Lists
* Stack Implementation
* Queue Implementation
* Pointers
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand the purpose of a deque.
* Implement insertion and deletion from both ends.
* Compare deque operations with stacks and queues.
* Understand practical applications of deques.
* Analyze the complexity of deque operations.

---

# 📂 Directory Structure

```text id="3h4v1z"
Deque/
├── STLStyleDeque/
│   └── Deque.cpp
├── CustomDeque/
│   └── Deque.cpp
└── README.md
```

---

# 🧠 The Core Idea

Unlike stacks and queues, a deque provides access to **both ends** of the data structure.

```text id="jy5el0"
Front                           Rear

+----+----+----+----+
| 10 | 20 | 30 | 40 |
+----+----+----+----+

↑                      ↑
Insert/Delete     Insert/Delete
```

Every primary operation occurs at either the **front** or the **rear**, making them efficient.

---

# ⚙️ Supported Operations

A deque typically supports:

* `push_front()`
* `push_back()`
* `pop_front()`
* `pop_back()`
* `front()`
* `back()`
* `isEmpty()`
* `size()`
* `clear()`

These operations make a deque more versatile than either a stack or a queue.

---

# 🏗️ Implementation 1 — STL-Style Deque

The STL-style implementation offers a familiar interface similar to `std::deque`.

Typical characteristics include:

* Efficient insertion at both ends.
* Efficient removal at both ends.
* Dynamic growth.
* Encapsulated implementation details.

This allows developers to focus on the interface while the container manages memory internally.

---

# 🛠️ Implementation 2 — Custom Deque

The custom implementation demonstrates the internal mechanics required to support operations at both ends.

Typical internal members may include:

```cpp id="0czpzg"
int front;
int rear;
int size;
```

Depending on the implementation, additional bookkeeping may be required to efficiently manage available storage and maintain the deque's state.

---

# 🔨 Front Operations

### Push Front

Before:

```text id="qun2z8"
Front

▼
20 → 30 → 40
```

Execute:

```cpp id="6sjys0"
push_front(10);
```

Result:

```text id="gxq7qh"
Front

▼
10 → 20 → 30 → 40
```

---

### Pop Front

```text id="kl7dcp"
10 → 20 → 30 → 40

↓

20 → 30 → 40
```

The first element is removed while the remaining elements stay in order.

---

# 🔨 Rear Operations

### Push Back

```text id="w7n6e6"
10 → 20 → 30

↓

10 → 20 → 30 → 40
```

The new element is appended at the rear.

---

### Pop Back

```text id="h7okh3"
10 → 20 → 30 → 40

↓

10 → 20 → 30
```

The last element is removed.

---

# 📊 Relationship with Other Data Structures

A deque can emulate both a stack and a queue.

```text id="rvpf4m"
             Deque
            /     \
           /       \
      Stack       Queue
```

### As a Stack

```cpp id="i7x9e3"
push_back()
pop_back()
```

---

### As a Queue

```cpp id="vswj6x"
push_back()
pop_front()
```

This versatility makes the deque one of the most flexible linear data structures.

---

# ⚡ Complexity Analysis

| Operation  | Time |
| ---------- | :--: |
| Push Front | O(1) |
| Push Back  | O(1) |
| Pop Front  | O(1) |
| Pop Back   | O(1) |
| Front      | O(1) |
| Back       | O(1) |

A well-designed deque provides constant-time access and modification at both ends.

---

# 🌍 Real-World Applications

Deques are commonly used in:

* Sliding Window Algorithms
* Browser History
* Undo / Redo Systems
* Task Scheduling
* Palindrome Checking
* LRU Cache Implementations
* Monotonic Queue Algorithms
* Buffer Management

Many advanced algorithms rely on the deque's ability to efficiently manipulate both ends of a sequence.

---

# ⚠️ Common Implementation Mistakes

When implementing a deque, beginners often:

* Confuse the front and rear indices.
* Mishandle the empty deque state.
* Forget to update both ends after insertions or deletions.
* Create invalid index calculations in array-based implementations.
* Fail to properly handle edge cases with a single element.

Testing boundary conditions is essential for a reliable implementation.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

* Circular Deque
* Monotonic Queue
* Sliding Window Maximum
* Design a Deque
* Palindrome Checker
* LRU Cache (using a deque with supporting data structures)

These exercises reinforce the flexibility and efficiency of deque operations.

---

# 📝 Key Takeaways

* A deque supports insertion and deletion at **both ends**.
* It generalizes the behavior of both stacks and queues.
* All primary operations run in **O(1)** time in a well-designed implementation.
* Understanding deque implementations builds a strong foundation for advanced algorithms such as Sliding Window and Monotonic Queue techniques.

---

# 🔗 Related Implementations

⬅️ **Queue** — Restricts insertion and deletion to opposite ends.

➡️ **Binary Tree** — Introduces hierarchical data structures and recursive traversal techniques.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home

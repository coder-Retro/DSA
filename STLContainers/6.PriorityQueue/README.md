# 👑 Priority Queue

`std::priority_queue` is a **container adapter** provided by the C++ Standard Template Library (STL). Unlike a regular queue, which processes elements in the order they are inserted (**FIFO**), a priority queue processes elements based on their **priority**.

By default, the element with the **highest value** has the highest priority and is removed first. Internally, `std::priority_queue` is typically implemented using a **binary heap**, making insertion and removal operations highly efficient.

---

# 📖 Prerequisites

Before studying this topic, you should be familiar with:

- Basic C++ syntax
- STL Containers
- Queue
- Binary Trees (recommended)
- Heap (recommended)

---

# 🎯 Learning Objectives

After completing this section, you should be able to:

- Understand how a priority queue differs from a regular queue.
- Create and initialize a `std::priority_queue`.
- Insert and remove elements efficiently.
- Build both Max Heaps and Min Heaps.
- Use custom comparators for user-defined priorities.
- Recognize problems where a priority queue is the ideal solution.

---

# 📂 Directory Structure

```text
6.PriorityQueue/
├── priorityqueue.cpp
└── README.md
```

---

# 📄 File Overview

## `priorityqueue.cpp`

This file introduces the core functionality of `std::priority_queue`.

### Topics Covered

- Creating a priority queue
- `push()`
- `pop()`
- `top()`
- `size()`
- `empty()`
- Max Heap (default behavior)
- Min Heap using `std::greater<>`
- Priority-based element retrieval

The examples demonstrate how elements are automatically ordered based on priority rather than insertion order.

---

# ⚡ Common Operations

| Operation | Complexity |
| --------- | ---------: |
| `push()`  |   O(log n) |
| `pop()`   |   O(log n) |
| `top()`   |       O(1) |
| `size()`  |       O(1) |
| `empty()` |       O(1) |

---

# 🔍 Queue vs Priority Queue

| Feature              |     Queue     |         Priority Queue         |
| -------------------- | :-----------: | :----------------------------: |
| Order                |     FIFO      |     Highest Priority First     |
| Removal              | Front Element |    Highest Priority Element    |
| Underlying Structure |     Deque     |          Binary Heap           |
| `top()` / `front()`  |     Front     |        Highest Priority        |
| Common Complexity    |     O(1)      | O(log n) for insertion/removal |

---

# 💡 Max Heap vs Min Heap

### Max Heap (Default)

The largest element has the highest priority.

Example:

```text
Insert: 10, 50, 20, 30

Removal Order:
50
30
20
10
```

---

### Min Heap

The smallest element has the highest priority.

Example:

```text
Insert: 10, 50, 20, 30

Removal Order:
10
20
30
50
```

---

# 🌍 Real-World Applications

Priority queues are used extensively in:

- CPU Scheduling
- Dijkstra's Shortest Path Algorithm
- Prim's Minimum Spanning Tree Algorithm
- Huffman Coding
- Event-Driven Simulation
- Network Routing
- Job Scheduling Systems
- Operating Systems

---

# 📌 Quick Reference

| Function  | Purpose                                   |
| --------- | ----------------------------------------- |
| `push()`  | Insert an element                         |
| `pop()`   | Remove the highest-priority element       |
| `top()`   | Access the highest-priority element       |
| `size()`  | Return the number of elements             |
| `empty()` | Check whether the priority queue is empty |

---

# 🎯 Suggested Practice

After completing this section, try implementing:

- K Largest Elements
- Merge K Sorted Arrays
- Merge K Sorted Linked Lists
- Top K Frequent Elements
- K Closest Points to Origin
- Running Median of a Stream
- Task Scheduler

These problems are frequently asked in coding interviews and highlight the strengths of priority queues.

---

# 📝 Key Takeaways

- `std::priority_queue` retrieves elements based on **priority**, not insertion order.
- By default, it behaves as a **Max Heap**.
- A **Min Heap** can be created using a custom comparator.
- Insertions and deletions are performed in **O(log n)** time.
- It is the preferred data structure for scheduling, shortest path algorithms, and many optimization problems.

---

# 🔗 Continue Learning

⬅️ Previous: [Queue](../4.Queue/README.md)

➡️ Next: Continue with the **Algorithms** section.

🏠 Back to: [STL Containers](../README.md)

🏠 Repository Home: [../../README.md](../../README.md)

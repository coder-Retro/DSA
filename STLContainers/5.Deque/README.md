# 📚 Deque

`std::deque` (Double-Ended Queue) is a sequence container provided by the C++ Standard Template Library (STL) that allows **fast insertion and deletion at both the front and the back**.

Unlike `std::vector`, which is optimized for operations at the end, and `std::list`, which sacrifices random access for insertion efficiency, `std::deque` provides a balanced approach by supporting efficient access and modifications from both ends.

---

## 📖 Prerequisites

Before studying this topic, you should be familiar with:

- Basic C++ syntax
- Loops and functions
- STL iterators
- std::vector (recommended)

---

# 🎯 Learning Objectives

After completing this section, you should be able to:

- Understand what a double-ended queue is.
- Create and initialize a `std::deque`.
- Insert and remove elements from both ends.
- Access elements efficiently.
- Traverse a deque using iterators and loops.
- Identify scenarios where a deque is a better choice than a vector or list.

---

# 📂 Directory Structure

```text
Deque/
├── deque.cpp
└── README.md
```

---

# 📄 File Overview

## `deque.cpp`

This file introduces the core operations of the C++ `std::deque`.

### Topics Covered

- Creating deques
- Initialization
- `push_front()`
- `push_back()`
- `pop_front()`
- `pop_back()`
- Accessing elements
- Traversing the container
- Common member functions

The examples demonstrate how a deque combines features of both vectors and linked lists while maintaining efficient performance.

---

# ⚡ Common Operations

| Operation        | Complexity |
| ---------------- | ---------: |
| Access by index  |       O(1) |
| Front Access     |       O(1) |
| Back Access      |       O(1) |
| `push_front()`   |       O(1) |
| `push_back()`    |       O(1) |
| `pop_front()`    |       O(1) |
| `pop_back()`     |       O(1) |
| Insert in middle |       O(n) |
| Search           |       O(n) |

---

# 🔍 Vector vs List vs Deque

| Feature           | Vector | List | Deque |
| ----------------- | :----: | :--: | :---: |
| Random Access     |   ✅   |  ❌  |  ✅   |
| Insert at Front   |   ❌   |  ✅  |  ✅   |
| Insert at Back    |   ✅   |  ✅  |  ✅   |
| Middle Insertion  |   ❌   |  ✅  |  ❌   |
| Contiguous Memory |   ✅   |  ❌  |  ❌   |

---

# 💡 When Should You Use a Deque?

Use `std::deque` when:

- You need frequent insertions at both the front and the back.
- Random access is still required.
- The sequence grows from both ends.
- Queue-like operations need additional flexibility.

Avoid using a deque when:

- You require contiguous memory (use `std::vector`).
- You frequently insert or erase elements in the middle (use `std::list`).

---

# 🌍 Real-World Applications

Double-ended queues are commonly used in:

- Sliding Window algorithms
- Task scheduling
- Browser history navigation
- Undo/Redo systems
- Palindrome checking
- Breadth-First Search (BFS)
- Monotonic Queue problems

---

# 📌 Quick Reference

| Function       | Purpose                                |
| -------------- | -------------------------------------- |
| `push_back()`  | Insert at the end                      |
| `push_front()` | Insert at the beginning                |
| `pop_back()`   | Remove the last element                |
| `pop_front()`  | Remove the first element               |
| `front()`      | Access the first element               |
| `back()`       | Access the last element                |
| `at()`         | Access an element with bounds checking |
| `size()`       | Return the number of elements          |
| `empty()`      | Check whether the deque is empty       |
| `clear()`      | Remove all elements                    |

---

# 📝 Key Takeaways

- `std::deque` stands for **Double-Ended Queue**.
- It provides **constant-time insertion and deletion at both ends**.
- It supports **random access**, unlike `std::list`.
- It is an excellent choice for algorithms that require operations from both ends of a sequence.

---

# 🔗 Continue Learning

⬅️ Previous: [List](../2.List/README.md)

➡️ Next: [Stack](../3.Stack/README.md)

🏠 Back to: [STL Containers](../README.md)

🏠 Repository Home: [../../README.md](../../README.md)

# 📋 List

`std::list` is a **doubly linked list** implementation provided by the C++ Standard Template Library (STL). Unlike `std::vector`, which stores elements in contiguous memory, a list stores elements as individually allocated nodes connected through pointers.

This design makes insertion and deletion operations extremely efficient once the desired position is known, while sacrificing direct random access.

---

# 🎯 Learning Objectives

After completing this section, you should be able to:

- Understand how a doubly linked list works.
- Create and initialize `std::list`.
- Insert and remove elements efficiently.
- Traverse a list using iterators.
- Understand why lists do not support random indexing.
- Decide when `std::list` is a better choice than `std::vector`.

---

# 📂 Directory Structure

```text
List/
├── list.cpp
└── README.md
```

---

# 📄 File Overview

## `list.cpp`

This file demonstrates the core functionality of `std::list`.

### Topics Covered

- Creating lists
- Initializing with values
- `push_front()`
- `push_back()`
- `pop_front()`
- `pop_back()`
- `insert()`
- `erase()`
- Traversing using iterators
- Common member functions

The examples are designed to help you understand how linked lists behave compared to dynamic arrays.

---

# ⚡ Common Operations

| Operation             |       Complexity |
| --------------------- | ---------------: |
| Access by index       | ❌ Not Supported |
| Front Access          |             O(1) |
| Back Access           |             O(1) |
| Insert at front       |             O(1) |
| Insert at back        |             O(1) |
| Insert using iterator |             O(1) |
| Erase using iterator  |             O(1) |
| Search                |             O(n) |

---

# 🔍 Vector vs List

| Feature           | `std::vector`  | `std::list`          |
| ----------------- | -------------- | -------------------- |
| Memory Layout     | Contiguous     | Non-contiguous       |
| Random Access     | ✅ O(1)        | ❌                   |
| Insert at Front   | O(n)           | O(1)                 |
| Insert at Back    | O(1) amortized | O(1)                 |
| Insert in Middle  | O(n)           | O(1) (with iterator) |
| Cache Performance | Excellent      | Lower                |

---

# 💡 When Should You Use a List?

Choose `std::list` when:

- Frequent insertions and deletions are required.
- Stable iterators are important.
- Random access is not needed.
- You're working with a sequence that changes often.

Avoid using `std::list` if you frequently access elements by index or need the best cache performance.

---

# 🌍 Real-World Applications

Doubly linked lists are useful in:

- Browser navigation (Back/Forward)
- Music playlists
- Undo/Redo systems
- LRU Cache implementations
- Task scheduling
- Text editors

---

# 📝 Key Takeaways

- `std::list` is implemented as a doubly linked list.
- It excels at insertion and deletion.
- It does **not** support direct indexing.
- Iterators are the primary way to traverse and modify a list.
- It trades memory efficiency and cache locality for flexibility.

---

# 🔗 Continue Learning

⬅️ Previous: [Vector](../1.Vector/README.md)

➡️ Next: [Deque](../5.Deque/README.md)

🏠 Back to: [STL Containers](../README.md)

🏠 Repository Home: [../../README.md](../../README.md)

## 📌 Quick Reference

| Function     | Purpose                       |
| ------------ | ----------------------------- |
| push_back()  | Insert at end                 |
| push_front() | Insert at beginning           |
| pop_back()   | Remove last element           |
| pop_front()  | Remove first element          |
| insert()     | Insert before an iterator     |
| erase()      | Remove element at an iterator |
| front()      | Access first element          |
| back()       | Access last element           |
| size()       | Number of elements            |
| empty()      | Check if the list is empty    |
| clear()      | Remove all elements           |

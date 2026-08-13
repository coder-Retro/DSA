# 📗 Vector

`std::vector` is the most commonly used container in the C++ Standard Template Library (STL). It represents a **dynamic array**, allowing elements to be added or removed while automatically managing memory.

Unlike a traditional array, a vector grows and shrinks as needed, making it a flexible and efficient choice for most programming tasks.

---

# 🎯 Learning Objectives

After completing this section, you should be able to:

- Create and initialize vectors.
- Access elements safely.
- Insert and remove elements.
- Understand dynamic resizing.
- Differentiate between `size()` and `capacity()`.
- Iterate through vectors using multiple techniques.

---

# 📂 Directory Structure

```text
Vector/
├── vector.cpp
├── dynamicVector.cpp
└── README.md
```

---

# 📄 File Overview

## `vector.cpp`

Introduces the fundamentals of `std::vector`.

Topics include:

- Declaration
- Initialization
- Accessing elements
- Traversing vectors
- Common member functions
- Insertion and deletion
- Iterators

This file is intended as the starting point for understanding dynamic arrays in C++.

---

## `dynamicVector.cpp`

Focuses on how vectors manage memory dynamically.

Topics include:

- Automatic resizing
- Capacity growth
- Memory allocation
- Performance considerations
- Reserving capacity

This example helps explain one of the biggest advantages of vectors over traditional arrays.

---

# ⚡ Common Operations

| Operation           |     Complexity |
| ------------------- | -------------: |
| Access by index     |           O(1) |
| `push_back()`       | O(1) amortized |
| `pop_back()`        |           O(1) |
| Insert at beginning |           O(n) |
| Insert in middle    |           O(n) |
| Erase               |           O(n) |
| Search              |           O(n) |

---

# 💡 When Should You Use a Vector?

Use a vector when:

- The number of elements is not known beforehand.
- Fast random access is required.
- Most insertions happen at the end.
- Simplicity and performance are both important.

Avoid using a vector when frequent insertions or deletions occur at the beginning or in the middle of the sequence.

---

# 🌍 Real-World Applications

Vectors are widely used in:

- Competitive programming
- Game development
- Data processing
- Scientific computing
- Machine learning
- General-purpose software development

For many applications, `std::vector` is the default container of choice.

---

# 🔗 Continue Learning

⬅️ Previous: [STL Containers](../README.md)

➡️ Next: [List](../2.List/README.md)

🏠 Back to: [Repository Home](../../README.md)

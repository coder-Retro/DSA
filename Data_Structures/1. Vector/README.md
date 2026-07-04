# 🏗️ Implementing a Dynamic Array (Vector)

> **"A vector is a dynamic array that automatically manages its own memory as elements are added or removed."**

Most C++ programmers use `std::vector` every day, but very few understand what happens behind the scenes.

This chapter focuses on **building a vector from scratch**, exploring the internal data members, memory management, resizing strategy, and the implementation of common operations such as `push_back()` and `pop_back()`.

By implementing your own vector, you'll gain a much deeper understanding of one of the most important data structures in modern C++.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

* Arrays
* Pointers
* Dynamic Memory Allocation (`new` / `delete`)
* Classes & Objects
* Constructors & Destructors

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand how a dynamic array works internally.
* Manage memory manually.
* Implement automatic resizing.
* Understand capacity growth.
* Analyze amortized time complexity.
* Build a simplified version of `std::vector`.

---

# 📂 Directory Structure

```text
Vector/
├── Vector.cpp
└── README.md
```

---

# 🧠 The Core Idea

Unlike a fixed-size array, a vector can **grow** as new elements are inserted.

Instead of allocating new memory for every insertion, a vector maintains two important values:

* **Size** → Number of elements currently stored.
* **Capacity** → Total allocated storage.

```text
Capacity = 8

+----+----+----+----+----+----+----+----+
| 12 | 18 | 25 | 31 |    |    |    |    |
+----+----+----+----+----+----+----+----+

Size = 4
Capacity = 8
```

The unused space allows future insertions without allocating memory every time.

---

# 🏗️ Internal Representation

A simplified vector typically contains three private data members:

```cpp
T* data;
size_t size;
size_t capacity;
```

### `data`

Points to the dynamically allocated array.

### `size`

Tracks the number of valid elements currently stored.

### `capacity`

Represents the amount of allocated storage.

The distinction between **size** and **capacity** is what makes dynamic arrays efficient.

---

# ⚙️ Supported Operations

A typical vector implementation supports:

* `push_back()`
* `pop_back()`
* `insert()`
* `erase()`
* `operator[]`
* `front()`
* `back()`
* `clear()`
* `resize()`
* `reserve()`

Each operation manipulates the internal array while maintaining the vector's invariants.

---

# 🔨 How `push_back()` Works

When there is available capacity:

```text
Before

Capacity = 8
Size = 4

+----+----+----+----+----+----+----+----+
| 10 | 20 | 30 | 40 |    |    |    |    |
+----+----+----+----+----+----+----+----+

push_back(50)

↓

+----+----+----+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |    |    |    |
+----+----+----+----+----+----+----+----+

Size = 5
```

Only the new element is inserted.

No memory allocation is required.

---

# 🔄 What Happens When Capacity Is Full?

Suppose the vector is completely filled.

```text
Capacity = 4

+----+----+----+----+
| 10 | 20 | 30 | 40 |
+----+----+----+----+
```

Now we execute:

```cpp
push_back(50);
```

The vector performs the following steps:

1. Allocate a larger block of memory.
2. Usually double the current capacity.
3. Copy existing elements.
4. Insert the new element.
5. Delete the old memory.
6. Update the internal pointer.

Result:

```text
Capacity = 8

+----+----+----+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |    |    |    |
+----+----+----+----+----+----+----+----+
```

This resizing strategy minimizes the number of memory allocations over time.

---

# ⚡ Complexity Analysis

| Operation       |       Time       |
| --------------- | :--------------: |
| Access          |       O(1)       |
| Update          |       O(1)       |
| `push_back()`   | O(1) *amortized* |
| `pop_back()`    |       O(1)       |
| Insert (Middle) |       O(n)       |
| Erase (Middle)  |       O(n)       |
| Search          |       O(n)       |

Although a resize is occasionally expensive, the **average** cost of `push_back()` remains constant, which is why it is considered **amortized O(1)**.

---

# 💾 Memory Ownership

Because the vector allocates memory dynamically, it is responsible for managing that memory.

A correct implementation must:

* Allocate memory when needed.
* Copy existing elements during resizing.
* Release old memory.
* Free all allocated memory in the destructor.

Improper memory management can lead to memory leaks or undefined behavior.

---

# 🌍 Real-World Applications

Dynamic arrays are used in:

* `std::vector`
* Game engines
* Graphics programming
* Web browsers
* Database systems
* Compilers
* Scientific computing

Many high-performance applications rely on dynamic arrays because they provide fast indexing while adapting to changing data sizes.

---

# ⚠️ Common Implementation Mistakes

When implementing your own vector, beginners often:

* Forget to update `size`.
* Ignore the difference between `size` and `capacity`.
* Leak memory during resizing.
* Forget to free memory in the destructor.
* Copy elements incorrectly.
* Access elements beyond the valid range.

Testing edge cases is essential for ensuring a robust implementation.

---

# 🎯 Suggested Exercises

Once you understand the implementation, try adding support for:

* `reserve()`
* `shrink_to_fit()`
* Copy Constructor
* Move Constructor
* Copy Assignment Operator
* Move Assignment Operator
* Iterator support
* Range-based `for` compatibility

These additions will bring your custom vector closer to the functionality of `std::vector`.

---

# 📝 Key Takeaways

* A vector is a dynamically resizing array.
* It maintains both **size** and **capacity**.
* Capacity grows to reduce the frequency of memory allocations.
* `push_back()` is **amortized O(1)** because resizing happens infrequently.
* Implementing a vector is an excellent exercise in memory management and object-oriented design.

---

# 🔗 Related Implementations

➡️ **Linked List** — A dynamic structure optimized for insertions and deletions.

➡️ **Stack** — Can be efficiently implemented using a vector.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home

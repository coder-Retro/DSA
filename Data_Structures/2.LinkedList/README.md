# 🔗 Implementing a Singly Linked List

> **"A linked list stores data as a chain of connected nodes rather than contiguous memory locations."**

Unlike vectors and arrays, a linked list does **not** store elements next to each other in memory. Instead, each element (called a **node**) contains the data itself along with a pointer to the next node in the sequence.

This design makes insertions and deletions efficient while sacrificing direct random access.

Implementing a linked list from scratch is one of the best ways to understand pointers, dynamic memory allocation, and node-based data structures.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

- Pointers
- Classes & Objects
- Dynamic Memory Allocation (`new` / `delete`)
- Constructors & Destructors
- Basic Object-Oriented Programming

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

- Understand how linked lists differ from arrays.
- Create and connect nodes dynamically.
- Traverse a linked list.
- Insert and delete nodes.
- Manage memory safely.
- Analyze the complexity of common operations.

---

# 📂 Directory Structure

```text id="w7d4pa"
2.LinkedList/
├── list.h
├── main.cpp
└── README.md
```

---

# 🧠 The Core Idea

Instead of storing data in contiguous memory, each node stores:

- The actual value.
- A pointer to the next node.

```text id="nlv4ib"
Head
 │
 ▼
+-------+------+     +-------+------+     +-------+------+
| Data  | Next | --> | Data  | Next | --> | Data  | NULL |
+-------+------+     +-------+------+     +-------+------+
```

Each node only knows where the **next** node is located.

---

# 🏗️ Internal Representation

A simple singly linked list consists of two components:

## Node

```cpp id="zw1vpc"
class Node
{
public:
    int data;
    Node* next;
};
```

Each node stores its value and the address of the next node.

---

## Linked List

```cpp id="zb0b1j"
class LinkedList
{
private:
    Node* head;
};
```

The `head` pointer marks the beginning of the list.

If `head == nullptr`, the list is empty.

---

# ⚙️ Supported Operations

A typical linked list implementation supports:

- Insert at Beginning
- Insert at End
- Insert at Position
- Delete from Beginning
- Delete from End
- Delete by Value
- Search
- Traverse
- Reverse
- Count Nodes

Each operation manipulates node pointers while preserving the structure of the list.

---

# 🔨 Inserting at the Beginning

Before:

```text id="u4lp5x"
Head
 │
 ▼
10 → 20 → 30 → NULL
```

Insert `5`.

Steps:

1. Create a new node.
2. Set `newNode->next = head`.
3. Update `head = newNode`.

Result:

```text id="cw4r3e"
Head
 │
 ▼
5 → 10 → 20 → 30 → NULL
```

This operation takes **O(1)** time because no traversal is required.

---

# 🔨 Inserting at the End

Before:

```text id="8c80b8"
10 → 20 → 30 → NULL
```

To insert `40`:

1. Traverse to the last node.
2. Create a new node.
3. Set the last node's `next` pointer to the new node.

Result:

```text id="8xvjlwm"
10 → 20 → 30 → 40 → NULL
```

This requires traversing the list, giving a time complexity of **O(n)**.

---

# 🔨 Deleting a Node

Deleting a node involves:

1. Locating the node.
2. Updating the previous node's `next` pointer.
3. Releasing the node's memory using `delete`.

Example:

```text id="bktc4w"
Before

10 → 20 → 30 → 40

Delete 30

↓

10 → 20 ─────► 40
```

Proper pointer updates are essential to avoid memory leaks and broken links.

---

# ⚡ Complexity Analysis

| Operation           |  Time  |
| ------------------- | :----: |
| Access by Index     |  O(n)  |
| Search              |  O(n)  |
| Insert at Beginning |  O(1)  |
| Insert at End       | O(n)\* |
| Delete at Beginning |  O(1)  |
| Delete at End       |  O(n)  |
| Traverse            |  O(n)  |

> _Insertion at the end can be reduced to **O(1)** if a `tail` pointer is maintained._

---

# 📊 Linked List vs Dynamic Array

| Feature         |          Linked List          |         Dynamic Array         |
| --------------- | :---------------------------: | :---------------------------: |
| Random Access   |            ❌ O(n)            |            ✅ O(1)            |
| Insert at Front |            ✅ O(1)            |            ❌ O(n)            |
| Insert at End   |            O(n)\*             |       ✅ Amortized O(1)       |
| Delete          | Efficient after locating node | May require shifting elements |
| Memory Layout   |        Non-contiguous         |          Contiguous           |

Each structure excels in different situations.

---

# 🌍 Real-World Applications

Linked lists are used in:

- Music playlists
- Browser navigation (Back/Forward)
- Undo/Redo systems
- Memory allocators
- Hash table chaining
- Graph adjacency lists
- LRU Cache implementations

---

# ⚠️ Common Implementation Mistakes

When implementing a linked list, beginners often:

- Forget to initialize `head`.
- Lose nodes by overwriting pointers.
- Forget to free memory with `delete`.
- Dereference `nullptr`.
- Fail to update `head` after deleting the first node.
- Create accidental cycles.

Always test:

- Empty lists
- Single-node lists
- Deleting the head
- Deleting the last node
- Consecutive insertions and deletions

---

# 🎯 Suggested Exercises

After understanding the implementation, try adding:

- Tail Pointer
- Recursive Traversal
- Recursive Reverse
- Detect Cycle (Floyd's Algorithm)
- Merge Two Sorted Lists
- Remove Duplicates
- Find the Middle Node
- Sort a Linked List

These exercises strengthen your understanding of pointer manipulation and dynamic memory management.

---

# 📝 Key Takeaways

- A linked list stores nodes connected by pointers rather than contiguous memory.
- Insertions and deletions at the beginning are efficient.
- Random access is slower because nodes must be traversed sequentially.
- Correct pointer management is essential for a safe and reliable implementation.

---

# 🔗 Related Implementations

⬅️ **Vector** — Efficient random access using contiguous memory.

➡️ **Stack** — Can be implemented using either a vector or a linked list.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home

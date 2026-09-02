# 🔗 Implementing Linked Lists (Singly & Doubly)

> **"A linked list stores data as a chain of connected nodes rather than contiguous memory locations."**

Unlike vectors and arrays, a linked list does **not** store elements next to each other in memory. Instead, each element (called a **node**) contains the data itself along with a pointer (or pointers) to neighboring nodes.

This design makes insertions and deletions efficient while sacrificing direct random access.

Implementing a linked list from scratch is one of the best ways to understand pointers, dynamic memory allocation, and node-based data structures. This chapter covers two variants:

- **Singly Linked List** — each node points to the next node only.
- **Doubly Linked List** — each node points to both the next and the previous node.

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
- Traverse a linked list in one or both directions.
- Insert and delete nodes from a singly or doubly linked list.
- Manage memory safely, including breaking cycles created by back-pointers.
- Analyze and compare the complexity of common operations across both variants.

---

# 📂 Directory Structure

```text
2.LinkedList/
├── 1.SinglyLinkedList
│   ├── list.h
│   └── main.cpp
├── 2.DoublyLinkedList
│   ├── list.h
│   └── main.cpp
└── README.md
```

---

# 🧠 The Core Idea

Instead of storing data in contiguous memory, each node stores its value plus one or more pointers to neighboring nodes.

## Singly Linked List

Each node only knows where the **next** node is located.

```text
Head
 │
 ▼
+-------+------+     +-------+------+     +-------+------+
| Data  | Next | --> | Data  | Next | --> | Data  | NULL |
+-------+------+     +-------+------+     +-------+------+
```

## Doubly Linked List

Each node knows both the **next** node and the **previous** node, allowing traversal in either direction.

```text
Head                                                      Tail
 │                                                          │
 ▼                                                          ▼
+------+------+------+     +------+------+------+     +------+------+------+
| Prev | Data | Next | <-> | Prev | Data | Next | <-> | Prev | Data | Next |
| NULL |  10  |      |     |      |  20  |      |     |      |  30  | NULL |
+------+------+------+     +------+------+------+     +------+------+------+
```

The extra `prev` pointer costs some memory but removes the need to re-traverse the list to reach a node's predecessor.

---

# 🏗️ Internal Representation

## Singly Linked List

### Node

```cpp
class Node
{
public:
    int data;
    Node* next;
};
```

### Linked List

```cpp
class LinkedList
{
private:
    Node* head;
};
```

The `head` pointer marks the beginning of the list. If `head == nullptr`, the list is empty.

---

## Doubly Linked List

### Node

```cpp
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};
```

Each node stores its value, the address of the next node, and the address of the previous node.

### Linked List

```cpp
class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
};
```

Maintaining both a `head` and a `tail` pointer lets the doubly linked list insert or delete at either end in **O(1)** time.

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
- Traverse (forward, and backward for doubly linked lists)
- Reverse
- Count Nodes

Each operation manipulates node pointers while preserving the structure of the list. In a doubly linked list, **every** pointer update must keep both `next` and `prev` consistent.

---

# 🔨 Inserting at the Beginning

## Singly Linked List

Before:

```text
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

```text
Head
 │
 ▼
5 → 10 → 20 → 30 → NULL
```

This operation takes **O(1)** time because no traversal is required.

## Doubly Linked List

Before:

```text
Head                          Tail
 │                              │
 ▼                              ▼
10 <-> 20 <-> 30
```

Insert `5`.

Steps:

1. Create a new node.
2. Set `newNode->next = head`.
3. Set `head->prev = newNode`.
4. Update `head = newNode`.
5. If the list was empty, also set `tail = newNode`.

Result:

```text
Head                                Tail
 │                                    │
 ▼                                    ▼
5 <-> 10 <-> 20 <-> 30
```

Still **O(1)**, with two extra pointer assignments compared to the singly linked version.

---

# 🔨 Inserting at the End

## Singly Linked List

Before:

```text
10 → 20 → 30 → NULL
```

To insert `40`:

1. Traverse to the last node.
2. Create a new node.
3. Set the last node's `next` pointer to the new node.

Result:

```text
10 → 20 → 30 → 40 → NULL
```

This requires traversing the list, giving a time complexity of **O(n)** — unless a `tail` pointer is maintained, which reduces it to **O(1)**.

## Doubly Linked List

Before:

```text
Head                    Tail
 │                        │
 ▼                        ▼
10 <-> 20 <-> 30
```

To insert `40`:

1. Create a new node.
2. Set `newNode->prev = tail`.
3. Set `tail->next = newNode`.
4. Update `tail = newNode`.

Result:

```text
Head                          Tail
 │                              │
 ▼                              ▼
10 <-> 20 <-> 30 <-> 40
```

Because a doubly linked list conventionally maintains a `tail` pointer, this is **O(1)** with no traversal needed.

---

# 🔨 Deleting a Node

## Singly Linked List

Deleting a node involves:

1. Locating the node **and** the node before it (since there's no `prev` pointer).
2. Updating the previous node's `next` pointer.
3. Releasing the node's memory using `delete`.

Example:

```text
Before

10 → 20 → 30 → 40

Delete 30

↓

10 → 20 ─────► 40
```

Proper pointer updates are essential to avoid memory leaks and broken links.

## Doubly Linked List

Deleting a node is simpler because the node already knows its own predecessor:

1. Locate the node directly (no need to track the previous node separately).
2. Set `node->prev->next = node->next` (if `node->prev` exists, otherwise update `head`).
3. Set `node->next->prev = node->prev` (if `node->next` exists, otherwise update `tail`).
4. Release the node's memory using `delete`.

Example:

```text
Before

10 <-> 20 <-> 30 <-> 40

Delete 30

↓

10 <-> 20 <────────> 40
```

Because each node has a `prev` pointer, deletion doesn't require a preliminary traversal to find the predecessor — only to locate the target node itself.

---

# ⚡ Complexity Analysis

## Singly Linked List

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

## Doubly Linked List

| Operation                    |  Time  |
| ----------------------------- | :----: |
| Access by Index               |  O(n)  |
| Search                        |  O(n)  |
| Insert at Beginning            |  O(1)  |
| Insert at End                 |  O(1)  |
| Delete at Beginning            |  O(1)  |
| Delete at End                 |  O(1)  |
| Delete a Known Node           |  O(1)  |
| Traverse (forward or backward) |  O(n)  |

> _Deleting a "known node" means you already hold a pointer to it — no search required. Deleting by value still costs **O(n)** to locate the node first._

---

# 📊 Comparing All Three Structures

| Feature              |       Singly Linked List       |          Doubly Linked List          |         Dynamic Array         |
| -------------------- | :-----------------------------: | :-----------------------------------: | :----------------------------: |
| Random Access        |              ❌ O(n)             |                ❌ O(n)                 |             ✅ O(1)             |
| Insert at Front       |              ✅ O(1)             |                ✅ O(1)                 |             ❌ O(n)             |
| Insert at End         |         O(n) / O(1) w/ tail      |                ✅ O(1)                 |        ✅ Amortized O(1)         |
| Delete at Front       |              ✅ O(1)             |                ✅ O(1)                 |             ❌ O(n)             |
| Delete at End         |               O(n)               |                ✅ O(1)                 |             ✅ O(1)             |
| Delete a Known Node   |    O(n) — must find predecessor  |                ✅ O(1)                 | O(n) — requires shifting        |
| Backward Traversal     |            ❌ Not possible        |                 ✅ O(n)                 |             ✅ O(1)             |
| Memory per Node       |         1 pointer overhead        |          2 pointers overhead           |          None (packed)          |
| Memory Layout         |          Non-contiguous           |            Non-contiguous              |            Contiguous           |

Each structure excels in different situations. A doubly linked list trades extra memory per node for cheaper deletions and bidirectional traversal.

---

# 🌍 Real-World Applications

## Singly Linked List

- Music playlists (forward-only)
- Undo systems (simple stack-like history)
- Memory allocators
- Hash table chaining
- Graph adjacency lists

## Doubly Linked List

- Browser navigation (Back/Forward)
- Text editor undo/redo with two-way navigation
- LRU Cache implementations (fast removal of arbitrary nodes)
- Music players with "previous track" support
- Deques (double-ended queues)

---

# ⚠️ Common Implementation Mistakes

When implementing a linked list, beginners often:

- Forget to initialize `head` (and `tail` for doubly linked lists).
- Lose nodes by overwriting pointers before saving a reference to them.
- Forget to free memory with `delete`.
- Dereference `nullptr`.
- Fail to update `head` after deleting the first node, or `tail` after deleting the last node.
- In doubly linked lists, update `next` but forget to update the matching `prev` (or vice versa), silently corrupting the list.
- Create accidental cycles.

Always test:

- Empty lists
- Single-node lists
- Deleting the head
- Deleting the last node
- Consecutive insertions and deletions
- For doubly linked lists: traversing backward from the tail after a mutation

---

# 🎯 Suggested Exercises

After understanding the implementation, try adding:

- Tail Pointer (for the singly linked list)
- Recursive Traversal
- Recursive Reverse
- Detect Cycle (Floyd's Algorithm)
- Merge Two Sorted Lists
- Remove Duplicates
- Find the Middle Node
- Sort a Linked List
- Convert a singly linked list into a doubly linked list
- Implement a circular doubly linked list

These exercises strengthen your understanding of pointer manipulation and dynamic memory management.

---

# 📝 Key Takeaways

- A linked list stores nodes connected by pointers rather than contiguous memory.
- A singly linked list only points forward; a doubly linked list points both forward and backward.
- Insertions and deletions at the beginning are efficient in both variants; doubly linked lists also make end operations and known-node deletions O(1).
- Random access is slower in both variants because nodes must be traversed sequentially.
- Correct pointer management is essential for a safe and reliable implementation — doubly linked lists require extra care to keep `next` and `prev` in sync.

---

# 🔗 Related Implementations

⬅️ **Vector** — Efficient random access using contiguous memory.

➡️ **Stack** — Can be implemented using either a vector or a linked list.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home
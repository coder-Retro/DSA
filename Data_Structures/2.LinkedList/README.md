# 🔗 Implementing Linked Lists (Singly, Doubly & Circular)

> **"A linked list stores data as a chain of connected nodes rather than contiguous memory locations."**

Unlike vectors and arrays, a linked list does **not** store elements next to each other in memory. Instead, each element (called a **node**) contains the data itself along with a pointer (or pointers) to neighboring nodes.

This design makes insertions and deletions efficient while sacrificing direct random access.

Implementing a linked list from scratch is one of the best ways to understand pointers, dynamic memory allocation, and node-based data structures. This chapter covers three variants:

- **Singly Linked List** — each node points to the next node only.
- **Doubly Linked List** — each node points to both the next and the previous node.
- **Circular Linked List** — each node points to the next node, and the last node points back to the first, forming a ring with no `nullptr` terminator.

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
- Insert and delete nodes from a singly, doubly, or circular linked list.
- Manage memory safely, including breaking cycles created by back-pointers or the circular wraparound.
- Analyze and compare the complexity of common operations across all variants.

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
├── 3.CircularLinkedList
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

## Circular Linked List

Each node only knows where the **next** node is located, exactly like a singly linked list — but instead of the last node's `next` being `nullptr`, it points back to the first node, closing the chain into a ring. There is no "end" to stop at; traversal only stops when you arrive back where you started.

```text
Head                                                      Tail
 │                                                          │
 ▼                                                          ▼
+-------+------+     +-------+------+     +-------+------+
| Data  | Next | --> | Data  | Next | --> | Data  | Next |
|  10   |      |     |  20   |      |     |  30   |   ●──┼──┐
+-------+------+     +-------+------+     +-------+------+  │
   ▲                                                         │
   └─────────────────────────────────────────────────────────┘
```

Because there is no `nullptr` terminator, every traversal loop (`find`, `copy`, `reverse`, printing, etc.) must use a **do-while** style loop that starts at `head` and stops when it revisits `head`, rather than the `while(node)` pattern used by singly/doubly linked lists. A single-node circular list still obeys this rule: that node's `next` must point to itself.

---

# 🏗️ Internal Representation

### Singly Linked List

```cpp
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
    size_t len;
};
```

The `head` pointer marks the beginning of the list. If `head == nullptr`, the list is empty.

---

Each node stores its value, the address of the next node, and the address of the previous node.

### Doubly Linked List

```cpp
template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    size_t len;
};
```

Maintaining both a `head` and a `tail` pointer lets the doubly linked list insert or delete at either end in **O(1)** time.

---

Structurally identical to the singly linked list — the difference is purely in how the pointers are wired together, not in the node layout.

### Circular Linked List

```cpp
template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
    size_t len;
};
```

The invariant that must hold at all times is `tail->next == head`. This is what turns a plain chain into a ring, and every insertion/removal routine is responsible for preserving it — including the very first node inserted into an empty list, which must point to itself (`newNode->next == newNode`).

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

Each operation manipulates node pointers while preserving the structure of the list. In a doubly linked list, **every** pointer update must keep both `next` and `prev` consistent. In a circular linked list, **every** pointer update must keep the ring closed — `tail->next` must always equal `head`, even transiently during multi-step operations.

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

## Circular Linked List

Before:

```text
Head                    Tail
 │                        │
 ▼                        ▼
10 → 20 → 30 ──┐
 ▲              │
 └──────────────┘
```

Insert `5`.

Steps:

1. Create a new node.
2. Set `newNode->next = head`.
3. Update `head = newNode`.
4. Re-link `tail->next = head` so the ring stays closed around the new head.
5. If the list was empty, instead set `head = tail = newNode` **and** `newNode->next = newNode` — the node must loop back to itself.

Result:

```text
Head                          Tail
 │                              │
 ▼                              ▼
5 → 10 → 20 → 30 ──┐
 ▲                  │
 └──────────────────┘
```

Still **O(1)** — no traversal needed — but note there's an extra step (step 4) compared to the singly linked version, since the tail's outgoing pointer must be kept pointing at whatever the current `head` is.

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

## Circular Linked List

Before:

```text
Head                    Tail
 │                        │
 ▼                        ▼
10 → 20 → 30 ──┐
 ▲              │
 └──────────────┘
```

To insert `40`:

1. Create a new node.
2. Set `tail->next = newNode`.
3. Update `tail = newNode`.
4. Re-link `tail->next = head` to close the ring around the new tail.
5. If the list was empty, instead set `head = tail = newNode` **and** `newNode->next = newNode`.

Result:

```text
Head                                Tail
 │                                    │
 ▼                                    ▼
10 → 20 → 30 → 40 ──┐
 ▲                   │
 └───────────────────┘
```

Because a `tail` pointer is maintained, this is **O(1)** — same as the doubly linked list — just with one link instead of two, since there's no `prev` to maintain.

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

## Circular Linked List

Deleting a node is structurally like the singly linked list — you still need the predecessor, since there's no `prev` pointer — but two extra cases need care because the ring must stay closed:

1. Locate the node **and** the node before it.
2. Updating the previous node's `next` pointer.
3. Releasing the node's memory using `delete`.
4. **Special case — deleting `head`:** advance `head` to `head->next`, then re-link `tail->next = head`.
5. **Special case — deleting `tail`:** find the new last node, make it the new `tail`, then re-link `tail->next = head`.
6. **Special case — deleting the only remaining node:** set both `head = tail = nullptr`. There's nothing to re-link — the ring is simply empty.

Example:

```text
Before

10 → 20 → 30 → 40 ──┐
 ▲                   │
 └───────────────────┘

Delete 30

↓

10 → 20 ─────► 40 ──┐
 ▲                   │
 └───────────────────┘
```

Every removal path — front, back, or middle — must leave `tail->next == head` true afterward, or every subsequent traversal in the list silently breaks.

---

# ⚡ Complexity Analysis

## Singly Linked List

| Operation           |  Time  |
| ------------------- | :----: |
| Access by Index     |  O(n)  |
| Search              |  O(n)  |
| Insert at Beginning |  O(1)  |
| Insert at End       |  O(1)  |
| Delete at Beginning |  O(1)  |
| Delete at End       |  O(n)  |
| Traverse            |  O(n)  |

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

## Circular Linked List

| Operation           |  Time  |
| -------------------- | :----: |
| Access by Index      |  O(n)  |
| Search                |  O(n)  |
| Insert at Beginning   |  O(1)  |
| Insert at End         |  O(1)  |
| Delete at Beginning    |  O(1)  |
| Delete at End         |  O(n)  |
| Reverse (in place)     |  O(n)  |
| Traverse (any starting node, wraps forever) | O(n) per full pass |

> _With a `tail` pointer maintained, insert-at-end is O(1), same as a singly linked list. Delete-at-end is still O(n) because finding the new tail requires walking from `head` — there's no `prev` pointer to jump back with, unlike the doubly linked list._

---

# 📊 Comparing All Four Structures

| Feature              |       Singly Linked List       |          Doubly Linked List          |         Circular Linked List         |         Dynamic Array         |
| -------------------- | :-----------------------------: | :-----------------------------------: | :-----------------------------------: | :----------------------------: |
| Random Access        |              ❌ O(n)             |                ❌ O(n)                 |                ❌ O(n)                 |             ✅ O(1)             |
| Insert at Front       |              ✅ O(1)             |                ✅ O(1)                 |                ✅ O(1)                 |             ❌ O(n)             |
| Insert at End         |              ✅ O(1)      |                ✅ O(1)                 |                ✅ O(1)                 |        ✅ Amortized O(1)         |
| Delete at Front       |              ✅ O(1)             |                ✅ O(1)                 |                ✅ O(1)                 |             ❌ O(n)             |
| Delete at End         |               O(n)               |                ✅ O(1)                 |                 O(n)                   |             ✅ O(1)             |
| Delete a Known Node   |    O(n) — must find predecessor  |                ✅ O(1)                 |     O(n) — must find predecessor       | O(n) — requires shifting        |
| Backward Traversal     |            ❌ Not possible        |                 ✅ O(n)                 |              ❌ Not possible            |             ✅ O(1)             |
| Continuous Traversal   |            ❌ Terminates at NULL  |             ❌ Terminates at NULL       |         ✅ Wraps forever (ring)         |            ❌ Fixed bounds        |
| Memory per Node       |         1 pointer overhead        |          2 pointers overhead           |           1 pointer overhead            |          None (packed)          |
| Memory Layout         |          Non-contiguous           |            Non-contiguous              |             Non-contiguous              |            Contiguous           |

Each structure excels in different situations. A doubly linked list trades extra memory per node for cheaper deletions and bidirectional traversal. A circular linked list trades the natural `nullptr` stopping point for the ability to cycle through elements indefinitely — useful whenever "the next element after the last one" should wrap back to the beginning.

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

## Circular Linked List

- Round-robin CPU scheduling
- Repeating/looping music playlists ("play on repeat")
- Multiplayer turn rotation (passing the turn back to player 1 after the last player)
- Circular buffers for streaming data
- Fibonacci/Josephus-style problems that require wrapping around a fixed set of elements

---

# ⚠️ Common Implementation Mistakes

When implementing a linked list, beginners often:

- Forget to initialize `head` (and `tail` for doubly/circular linked lists).
- Lose nodes by overwriting pointers before saving a reference to them.
- Forget to free memory with `delete`.
- Dereference `nullptr`.
- Fail to update `head` after deleting the first node, or `tail` after deleting the last node.
- In doubly linked lists, update `next` but forget to update the matching `prev` (or vice versa), silently corrupting the list.
- In circular linked lists, use a `while(node)` traversal loop out of habit — this **never terminates**, since `tail->next` never becomes `nullptr`. Every traversal must instead check "have I returned to where I started?"
- In circular linked lists, forget to make a newly-inserted first node point to itself (`newNode->next = newNode`) — this silently breaks the ring invariant for every method that follows, often not surfacing as a bug until the list has 1 element and a traversal is attempted.
- Create accidental cycles (in singly/doubly linked lists, where none should exist) — or, conversely, accidentally *break* the intended cycle (in circular linked lists, where one should always exist).

Always test:

- Empty lists
- Single-node lists
- Deleting the head
- Deleting the last node
- Consecutive insertions and deletions
- For doubly linked lists: traversing backward from the tail after a mutation
- For circular linked lists: that `tail->next == head` holds after **every** mutation, including on the very first insert

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
- Implement the Josephus Problem using a circular linked list

These exercises strengthen your understanding of pointer manipulation and dynamic memory management.

---

# 📝 Key Takeaways

- A linked list stores nodes connected by pointers rather than contiguous memory.
- A singly linked list only points forward; a doubly linked list points both forward and backward; a circular linked list points forward and wraps back to the start instead of terminating.
- Insertions and deletions at the beginning are efficient in all three variants; doubly linked lists also make end operations and known-node deletions O(1).
- Random access is slower in all three variants because nodes must be traversed sequentially.
- Correct pointer management is essential for a safe and reliable implementation — doubly linked lists require extra care to keep `next` and `prev` in sync, while circular linked lists require every operation to preserve the `tail->next == head` invariant, including the very first node inserted.

---

# 🔗 Related Implementations

⬅️ **Vector** — Efficient random access using contiguous memory.

➡️ **Stack** — Can be implemented using either a vector or a linked list.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home
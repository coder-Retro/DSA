# 🚦 Implementing a Queue

> **"A queue is a First-In, First-Out (FIFO) data structure where the first element inserted is the first one to be removed."**

A queue models many real-world waiting lines. Just as people join a line at the back and leave from the front, a queue inserts elements at the **rear** and removes them from the **front**.

Unlike a stack, which only allows access from one end, a queue requires managing **two separate ends** efficiently.

This chapter explores multiple queue implementations, demonstrating how the same abstract data type can be built using different underlying techniques.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

* Dynamic Arrays (Vectors)
* Linked Lists
* Pointers
* Classes & Objects
* Dynamic Memory Allocation
* Stack Implementation

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand the FIFO principle.
* Implement a queue from scratch.
* Manage front and rear pointers correctly.
* Compare different implementation strategies.
* Analyze the complexity of queue operations.

---

# 📂 Directory Structure

```text id="ak2ngq"
Queue/
├── STLStyleQueue/
│   └── Queue.cpp
├── CustomQueue/
│   └── Queue.cpp
└── README.md
```

---

# 🧠 The Core Idea

A queue always follows the **First-In, First-Out (FIFO)** principle.

```text id="j4nkqu"
Front                           Rear

+-----+-----+-----+-----+
| 10  | 20  | 30  | 40  |
+-----+-----+-----+-----+

Dequeue  ←           →  Enqueue
```

The oldest element leaves first, while new elements always join at the rear.

---

# ⚙️ Supported Operations

A typical queue implementation supports:

* `enqueue()`
* `dequeue()`
* `front()`
* `rear()`
* `isEmpty()`
* `size()`
* `clear()`

Regardless of the implementation, these operations define the queue's behavior.

---

# 🏗️ Implementation 1 — STL-Style Queue

This implementation provides an interface similar to `std::queue`.

Internally, the underlying storage may vary, but the public interface remains consistent.

```text id="wrhgqt"
Front

▼
+----+----+----+
| 10 | 20 | 30 |
+----+----+----+
              ▲
             Rear
```

### Characteristics

* Clean interface
* Encapsulated implementation
* Efficient FIFO operations
* Easy to extend

---

# 🛠️ Implementation 2 — Custom Queue

The custom implementation exposes the internal mechanics of a queue.

Typical internal data members include:

```cpp id="xshq9s"
int front;
int rear;
int size;
```

These members track the current state of the queue and ensure elements are inserted and removed in the correct order.

Implementing these operations manually provides valuable insight into how queue behavior is maintained.

---

# 🔨 Enqueue Operation

Before:

```text id="wwtijb"
Front        Rear

+----+----+----+
| 10 | 20 | 30 |
+----+----+----+
```

Execute:

```cpp id="a7ll7g"
enqueue(40);
```

Result:

```text id="5sqnj7"
Front            Rear

+----+----+----+----+
| 10 | 20 | 30 | 40 |
+----+----+----+----+
```

The new element is always inserted at the rear.

---

# 🔨 Dequeue Operation

Before:

```text id="v0z8kp"
Front

▼
+----+----+----+
| 10 | 20 | 30 |
+----+----+----+
```

Execute:

```cpp id="6nrgjo"
dequeue();
```

Result:

```text id="rzqfbs"
Front

▼
+----+----+
| 20 | 30 |
+----+----+
```

The front element is removed, and the front advances to the next element.

---

# ⚡ Complexity Analysis

| Operation | Time |
| --------- | :--: |
| Enqueue   | O(1) |
| Dequeue   | O(1) |
| Front     | O(1) |
| Rear      | O(1) |
| isEmpty   | O(1) |

A properly implemented queue provides constant-time performance for all primary operations.

---

# 📊 Queue vs Stack

| Feature     |    Queue   |     Stack    |
| ----------- | :--------: | :----------: |
| Order       |    FIFO    |     LIFO     |
| Insert      |    Rear    |      Top     |
| Remove      |    Front   |      Top     |
| Ends Used   |     Two    |      One     |
| Typical Use | Scheduling | Backtracking |

Although both are linear data structures, they solve very different classes of problems.

---

# 🌍 Real-World Applications

Queues are widely used in:

* CPU Scheduling
* Printer Spooling
* Task Scheduling
* Breadth-First Search (BFS)
* Web Server Request Handling
* Customer Service Systems
* Network Packet Processing
* Simulation Systems

---

# ⚠️ Common Implementation Mistakes

When implementing a queue, beginners often:

* Confuse the `front` and `rear` pointers.
* Remove elements from the wrong end.
* Forget to update the queue after the last element is removed.
* Ignore queue overflow or underflow conditions.
* Mishandle the empty queue state.

Carefully maintaining the queue's internal state is essential for a correct implementation.

---

# 💡 A Note on Circular Queues

A simple array-based queue may waste space as elements are removed from the front.

A **Circular Queue** solves this by allowing the front and rear indices to wrap around to the beginning of the array, making better use of allocated memory.

Although this repository focuses on the current implementations, understanding circular queues is a valuable next step.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

* Circular Queue
* Double-Ended Queue (Deque)
* Queue using Two Stacks
* Priority Queue
* Job Scheduler Simulation
* Print Queue Simulation

These exercises build on the concepts introduced in this chapter.

---

# 📝 Key Takeaways

* A queue follows the **First-In, First-Out (FIFO)** principle.
* Elements are inserted at the rear and removed from the front.
* Managing the front and rear correctly is central to a successful implementation.
* Different internal implementations provide the same external behavior.
* Queues are fundamental to scheduling, traversal algorithms, and real-world systems.

---

# 🔗 Related Implementations

⬅️ **Stack** — Uses the opposite access order (**LIFO**).

➡️ **Deque** — Extends the queue by allowing insertion and removal from both ends.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home

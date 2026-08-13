<img src="https://capsule-render.vercel.app/api?type=venom&height=200&color=gradient&text=STL%20Containers&fontSize=50&fontColor=FFFFFF&animation=fadeIn&fontAlignY=35&desc=Vector%20%7C%20List%20%7C%20Tree&descSize=30&descColor=FFFFFF&descAlignY=65" width="100%"/>

# 📦 STL Containers

The **Standard Template Library (STL)** is one of the most powerful features of modern C++. It provides ready-to-use implementations of common data structures and algorithms, allowing developers to write efficient, clean, and maintainable code.

This directory introduces the most commonly used STL containers through practical examples and small programs. It is intended to build familiarity with the STL before moving on to implementing custom data structures and solving algorithmic problems.

---

# 🎯 Learning Objectives

After completing this section, you should be able to:

- Understand the purpose of the C++ Standard Template Library.
- Choose the appropriate container for a given problem.
- Perform common operations such as insertion, deletion, traversal, and access.
- Understand the strengths and limitations of each container.
- Apply STL containers to interview and competitive programming problems.

---

# 📂 Directory Structure

```text
STLContainers/
├── 1.Vector/
├── 2.List/
├── 3.Stack/
├── 4.Queue/
├── 5.Deque/
├── 6.PriorityQueue/
└── README.md
```

Each folder focuses on one container and contains runnable examples demonstrating its core functionality.

---

# 📚 Contents

## 📌 Vector

Files:

- `vector.cpp`
- `dynamicVector.cpp`

### Topics Covered

- Creating vectors
- Dynamic resizing
- Element access
- Iteration
- Common member functions
- Capacity management

### Best Used When

- Fast random access is required.
- Elements are mostly added at the end.
- A dynamic array is preferred over a fixed-size array.

---

## 📌 List

File:

- `list.cpp`

### Topics Covered

- Doubly linked list operations
- Insertion and deletion
- Forward and backward traversal
- Iterator usage

### Best Used When

- Frequent insertion or deletion in the middle of the sequence is required.
- Random access is not important.

---

## 📌 Stack

Files:

- `stack.cpp`
- `PracticeProblems/reverserStack.cpp`

### Topics Covered

- LIFO (Last-In, First-Out)
- Push and pop operations
- Top element access
- Practical stack manipulation

### Practice

The included practice problem demonstrates how stack operations can be applied to solve real programming challenges.

---

## 📌 Queue

Files:

- `queue.cpp`
- `PracticeProblems/reverserQueue.cpp`

### Topics Covered

- FIFO (First-In, First-Out)
- Enqueue and dequeue
- Front and rear access
- Practical queue manipulation

### Practice

Includes an implementation that reinforces queue operations through a simple problem.

---

## 📌 Deque

File:

- `deque.cpp`

### Topics Covered

- Double-ended insertion
- Double-ended deletion
- Random access
- Front and back operations

### Best Used When

- Efficient operations are needed at both the front and the back.

---

## 📌 Priority Queue

File:

- `priorityqueue.cpp`

### Topics Covered

- Max Heap
- Min Heap
- Custom ordering
- Priority-based processing

### Applications

- Scheduling
- Dijkstra's Algorithm
- Huffman Coding
- Greedy Algorithms
- Event simulation

---

# 📊 Container Comparison

| Container      |  Random Access   | Insert/Delete Front | Insert/Delete Back | Insert/Delete Middle |
| -------------- | :--------------: | :-----------------: | :----------------: | :------------------: |
| Vector         |    ⭐⭐⭐⭐⭐    |         ⭐          |     ⭐⭐⭐⭐⭐     |         ⭐⭐         |
| List           |        ❌        |     ⭐⭐⭐⭐⭐      |     ⭐⭐⭐⭐⭐     |      ⭐⭐⭐⭐⭐      |
| Deque          |     ⭐⭐⭐⭐     |     ⭐⭐⭐⭐⭐      |     ⭐⭐⭐⭐⭐     |         ⭐⭐         |
| Stack          |     Top Only     |         ❌          |     ⭐⭐⭐⭐⭐     |          ❌          |
| Queue          | Front/Back Only  |     ⭐⭐⭐⭐⭐      |     ⭐⭐⭐⭐⭐     |          ❌          |
| Priority Queue | Highest Priority |         ❌          |     Automatic      |          ❌          |

---

# 💡 Choosing the Right Container

| Use Case                          | Recommended Container |
| --------------------------------- | --------------------- |
| Dynamic array                     | `vector`              |
| Frequent middle insertion         | `list`                |
| Efficient front & back operations | `deque`               |
| Expression evaluation             | `stack`               |
| Breadth-First Search (BFS)        | `queue`               |
| Priority scheduling               | `priority_queue`      |

---

# 🚀 Recommended Learning Order

Study the folders in the following order:

1. Vector
2. List
3. Stack
4. Queue
5. Deque
6. Priority Queue

This sequence builds progressively from general-purpose containers to specialized data structures.

---

# 🔗 Related Topics

Once you're comfortable with STL containers, continue with:

- Algorithms
- Arrays
- Linked Lists
- Trees
- Graphs
- Problem Solving Patterns

Understanding the STL will make implementing and analyzing these topics significantly easier.

---

# 📌 Notes

The examples in this directory focus on understanding container behavior through practical code. While the STL offers many advanced features, this section emphasizes the operations and patterns most commonly encountered in software development, coding interviews, and competitive programming.

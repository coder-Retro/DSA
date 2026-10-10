# ⛰️ Implementing a Heap (MinHeap & MaxHeap)

> **"A heap keeps the most important element always one step away, at the top."**

A **Heap** is a specialized **complete binary tree** that satisfies the **heap property**. It is the data structure behind **priority queues**, letting you repeatedly retrieve the smallest (or largest) element efficiently.

There are two variants:

- **MinHeap:** every parent is **less than or equal to** its children, so the **smallest** element is at the root.
- **MaxHeap:** every parent is **greater than or equal to** its children, so the **largest** element is at the root.

Although a heap is conceptually a tree, it is stored in a plain **array (`std::vector`)**, with no pointers or nodes required.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

- Vectors (Dynamic Arrays)
- Binary Trees
- Recursion
- Templates (Generic Programming)
- Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

- Understand the heap property and the complete-tree shape.
- Map a binary tree onto an array using index arithmetic.
- Implement `push` using **heapify up** (sift up).
- Implement `pop` using **heapify down** (sift down).
- Convert a MinHeap into a MaxHeap by flipping the comparison.
- Analyze the complexity of heap operations.

---

# 📂 Directory Structure

```text
7.Heap/
├── MaxHeap/
├── MinHeap/
└── README.md
```

---

# 🧠 The Core Idea

A heap has two defining rules:

1. **Shape property:** the tree is *complete*. Every level is full except possibly the last, which is filled from left to right.
2. **Heap property:** every parent is ordered relative to its children (smaller for a MinHeap, larger for a MaxHeap).

```text
MinHeap as a tree:

            1
          /   \
         3     2
        / \   /
       7   4 5
```

Notice that only parent-to-child ordering is guaranteed. Siblings and cousins have **no** ordering between them, so a heap is **not** a sorted structure.

---

# 🗂️ Array Representation

Because the tree is complete, it packs perfectly into an array with no gaps.

```text
Tree:                 Array:

            1         index:  0  1  2  3  4  5
          /   \       value: [1, 3, 2, 7, 4, 5]
         3     2
        / \   /
       7   4 5
```

For a node at index `i` (**0-based**):

| Relation    | Formula        |
| ----------- | -------------- |
| Parent      | `(i - 1) / 2`  |
| Left child  | `2 * i + 1`    |
| Right child | `2 * i + 2`    |

```cpp
size_t parent(size_t i) { return (i - 1) / 2; }
size_t left(size_t i)   { return 2 * i + 1;   }
size_t right(size_t i)  { return 2 * i + 2;   }
```

> ⚠️ If you use **1-based** indexing instead, the formulas become `i / 2`, `2i`, and `2i + 1`. Pick one convention and use it everywhere.

---

# ⚙️ Supported Operations

A heap typically supports:

- `push()`
- `pop()`
- `top()`
- `empty()`
- `size()`

There is no random access and no search. The heap exists to answer one question quickly: *"what is the best element right now?"*

---

# 🏗️ Implementation 1 — MinHeap

The MinHeap keeps the **smallest** element at index `0`.

Typical internal member:

```cpp
std::vector<T> heap;
```

The class is a template, so it works for any type `T` that supports `operator<` (and `operator>` in the version shown here).

---

# 🏗️ Implementation 2 — MaxHeap

The MaxHeap keeps the **largest** element at index `0`.

It is structurally **identical** to the MinHeap. The only difference is that every comparison is flipped:

| MinHeap           | MaxHeap           |
| ----------------- | ----------------- |
| `heap[idx] < heap[p]` | `heap[idx] > heap[p]` |
| `heap[left] < heap[target]` | `heap[left] > heap[target]` |

---

# 🔨 Push (Heapify Up)

New elements are appended at the end of the array, which keeps the tree complete. That may break the heap property, so the element **bubbles up** until it is in the right place.

Before (MinHeap):

```text
        2
       / \
      5   3
```

Execute:

```cpp
push(1);
```

Step 1: append at the end.

```text
        2
       / \
      5   3
     /
    1          ← 1 < parent (5), swap
```

Step 2: swap with parent until the parent is smaller.

```text
        1
       / \
      2   3
     /
    5
```

```cpp
void heapifyUp(size_t idx) {
    if (!idx) return;                 // reached the root
    size_t p = (idx - 1) / 2;
    if (heap[idx] < heap[p]) {
        std::swap(heap[idx], heap[p]);
        heapifyUp(p);
    }
}
```

At most one swap per level, so push is **O(log n)**.

---

# 🔨 Pop (Heapify Down)

The root is the element being removed. To keep the tree complete, the **last** element is moved into the root, then **sinks down** until the heap property is restored.

Before (MinHeap):

```text
        1
       / \
      2   3
     / \
    5   4
```

Execute:

```cpp
pop();
```

Step 1: move the last element (4) to the root and shrink the array.

```text
        4
       / \
      2   3
     /
    5            ← 4 > smaller child (2), swap
```

Step 2: swap with the **smaller** child (MinHeap) until no child is smaller.

```text
        2
       / \
      4   3
     /
    5
```

```cpp
void heapifyDown(size_t idx) {
    size_t left = idx * 2 + 1;
    size_t right = idx * 2 + 2;
    size_t target = idx;
    if (left < heap.size() && heap[left] < heap[target])   target = left;
    if (right < heap.size() && heap[right] < heap[target]) target = right;
    if (target != idx) {
        std::swap(heap[idx], heap[target]);
        heapifyDown(target);
    }
}
```

`target` ends up as the smallest of the node and its two children. Each child's bounds are checked **separately**, so a node with only a left child is handled correctly. Pop is **O(log n)**.

---

# 📊 Relationship with Other Data Structures

```text
        Complete Binary Tree
                 |
                Heap
              /      \
         MinHeap    MaxHeap
              \      /
          Priority Queue
```

- A heap is a **complete binary tree** stored in an array.
- A **priority queue** is the abstract idea. A heap is the most common way to implement it.
- `std::priority_queue` is a **MaxHeap** by default. Use `std::greater<T>` for a MinHeap.

---

# ⚡ Complexity Analysis

| Operation  | Time     |
| ---------- | :------: |
| Push       | O(log n) |
| Pop        | O(log n) |
| Top        | O(1)     |
| Size       | O(1)     |
| Empty      | O(1)     |
| Build Heap (from n elements) | O(n) |

**Space complexity:** O(n)

Both `push` and `pop` travel along a single root-to-leaf path, and the height of a complete binary tree with `n` nodes is `⌊log₂ n⌋`.

---

# 🌍 Real-World Applications

Heaps are commonly used in:

- Priority Queues
- Heap Sort
- Dijkstra's Shortest Path Algorithm
- Prim's Minimum Spanning Tree
- Top-K Elements Problems
- Finding the Median of a Data Stream (two heaps)
- Task and Event Scheduling
- Huffman Coding
- Merging K Sorted Lists

---

# ⚠️ Common Implementation Mistakes

When implementing a heap, beginners often:

- **Mix 0-based and 1-based indexing**, for example using `2*i` and `2*i + 1` on a 0-based vector.
- **Underflow the parent index:** `(0 - 1) / 2` with `size_t` wraps to a huge number. Check for the root *before* computing the parent.
- **Read a missing child:** a node can have a left child but no right child. Check `left < size` and `right < size` independently.
- **Heapify the whole array on every push** instead of sifting up only from the new element (this turns O(log n) into O(n)).
- **Forget the single-element case in `pop`:** after `pop_back()` the heap may be empty, so skip `heapifyDown`.
- **Leave a hard-coded `int` inside a template**, such as `int poppedVal = heap[0];`, which silently truncates `double` and fails to compile for `std::string`.
- **Pick the wrong child when sifting down:** swap with the smaller child in a MinHeap and the larger child in a MaxHeap.

Testing boundary conditions (empty, one element, two elements, left-only child) is essential for a reliable implementation.

---

# 🧪 Suggested Test

Push values in descending order into a MinHeap, then pop repeatedly:

```cpp
MinHeap<int> h;
for (int x : {5, 4, 3, 2, 1}) h.push(x);
while (!h.empty()) std::cout << h.pop() << ' ';   // 1 2 3 4 5
```

This exercises both sift directions. Repeat with a MaxHeap and ascending input.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

- Generic `Compare` template parameter (`std::less<T>` / `std::greater<T>`) to merge MinHeap and MaxHeap into one class
- Move semantics (`push(T&&)`, `std::move` in `pop`)
- Iterative `heapifyUp` / `heapifyDown`
- Build Heap from a vector in O(n)
- Heap Sort
- Kth Largest Element in an Array
- Merge K Sorted Lists
- Find Median from Data Stream
- Priority Queue with custom structs

---

# 📝 Key Takeaways

- A heap is a **complete binary tree** stored in a **contiguous array**.
- The root always holds the **minimum** (MinHeap) or **maximum** (MaxHeap).
- `push` appends and **sifts up**. `pop` moves the last element to the root and **sifts down**.
- `push` and `pop` run in **O(log n)**, and `top` runs in **O(1)**.
- A MinHeap and MaxHeap differ only by the direction of their comparisons.
- A heap is **not sorted**, only partially ordered. It guarantees the top element and nothing else.

---

# 🔗 Related Implementations

⬅️ **Binary Tree**: Introduces hierarchical data structures and recursive traversal, the foundation for the heap's tree shape.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home
# 🔻 Implementing a MinHeap

> **"A MinHeap always keeps the smallest element at the top, one step away."**

A **MinHeap** is a **complete binary tree** in which every parent is **less than or equal to** its children. This guarantees that the **smallest** element is always at the root, so it can be read instantly and removed in logarithmic time.

This implementation is a **generic, array-backed MinHeap** built on `std::vector<T>`. The tree is never stored with nodes or pointers. Parent and child positions are computed with index arithmetic.

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

- Explain the min-heap property.
- Use index formulas to navigate a tree stored in an array.
- Implement `push` with **heapify up**.
- Implement `pop` with **heapify down**.
- Handle edge cases: empty heap, single element, left-only child.
- Analyze the complexity of each operation.

---

# 📂 Directory Structure

```text
MinHeap/
├── main.cpp
├── minheap.h
└── README.md
```

| File         | Purpose                                              |
| ------------ | ---------------------------------------------------- |
| `minheap.h`  | The templated `MinHeap<T>` class                     |
| `main.cpp`   | Driver code that exercises the heap                  |
| `README.md`  | This document                                        |

---

# 🧠 The Core Idea

The min-heap property: for every node, `parent <= child`.

```text
MinHeap as a tree:

            1
          /   \
         3     2
        / \   /
       7   5 4
```

Stored in an array, level by level:

```text
index:  0  1  2  3  4  5
value: [1, 3, 2, 7, 5, 4]
```

Only the parent-to-child relationship is ordered. Siblings have no required order (3 and 2 above), so a heap is **not sorted**. It only guarantees that the minimum is at index `0`.

---

# 🗂️ Index Arithmetic (0-based)

For a node at index `i`:

| Relation    | Formula       |
| ----------- | ------------- |
| Parent      | `(i - 1) / 2` |
| Left child  | `2 * i + 1`   |
| Right child | `2 * i + 2`   |

```text
          i = 1  (value 3)
         /          \
  left = 3 (7)    right = 4 (5)

  parent of 4  →  (4 - 1) / 2 = 1  ✔
```

---

# ⚙️ Supported Operations

| Operation | Description                                    |
| --------- | ---------------------------------------------- |
| `push(v)` | Insert a value                                 |
| `pop()`   | Remove and return the smallest value           |
| `top()`   | Return the smallest value without removing it  |
| `size()`  | Number of elements                             |
| `empty()` | Whether the heap has no elements               |

`pop()` and `top()` throw `std::underflow_error` if the heap is empty.

---

# 🏗️ The Implementation

`minheap.h`:

```cpp
#include<vector>
#include<utility>
#include<stdexcept>

template <typename T>
class MinHeap {
private:
    std::vector<T> heap;
    void heapifyUp(size_t idx) {
        if(!idx) return;
        size_t p=(idx-1)/2;
        if(heap[idx]<heap[p]) {
            std::swap(heap[idx],heap[p]);
            heapifyUp(p);
        }
    }
    void heapifyDown(size_t idx) {
        size_t left=idx*2+1;
        size_t right=idx*2+2;
        size_t target=idx;
        if(left<heap.size() && heap[left]<heap[target])   target=left;
        if(right<heap.size() && heap[right]<heap[target]) target=right;
        if(target!=idx) {
            std::swap(heap[idx],heap[target]);
            heapifyDown(target);
        }
    }
public:
    void push(const T& val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }
    T pop() {
        if(heap.empty()) throw std::underflow_error("MinHeap is empty");
        T poppedVal=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        if(!heap.empty()) heapifyDown(0);
        return poppedVal;
    }
    T top() const {
        if(heap.empty()) throw std::underflow_error("MinHeap is empty");
        return heap[0];
    }
    size_t size() const { return heap.size(); }
    bool empty() const { return heap.empty(); }
};
```

**Requirement on `T`:** it must support `operator<`, be copy-constructible, and be copy-assignable.

---

# 🔨 Push (Heapify Up)

The new value is appended at the end, which keeps the tree complete. If it is smaller than its parent, it **bubbles up** by swapping until its parent is smaller or it reaches the root.

Before:

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
   (1)           ← 1 < parent (5), swap
```

Step 2: keep swapping upward.

```text
        1
       / \
      2   3
     /
    5
```

**Base case:** `if(!idx) return;` runs *before* the parent is computed. With `size_t`, `(0 - 1) / 2` would wrap around to a huge number.

---

# 🔨 Pop (Heapify Down)

The root holds the minimum. To remove it while keeping the tree complete:

1. Save the root value to return it.
2. Move the **last** element into the root.
3. Remove the last slot with `pop_back()`.
4. **Sink** the new root down until it is no larger than both children.

Before:

```text
        1
       / \
      2   3
     / \
    5   4
```

Execute:

```cpp
pop();    // returns 1
```

Step 1: move the last element (4) to the root.

```text
        4
       / \
      2   3
     /
    5           ← 4 > smaller child (2), swap
```

Step 2: swap with the **smaller** child until the heap property holds.

```text
        2
       / \
      4   3
     /
    5
```

In `heapifyDown`, `target` starts as the node itself, then becomes the left child if it is smaller, then the right child if it is smaller still. By the end, `target` is the smallest of the three. Each child's bounds are checked **independently**, so a node with only a left child is handled safely.

---

# 🧪 Example Usage

```cpp
#include <iostream>
#include "minheap.h"

int main() {
    MinHeap<int> h;
    for (int x : {5, 4, 3, 2, 1}) h.push(x);

    std::cout << "Top: " << h.top() << '\n';      // 1
    std::cout << "Size: " << h.size() << '\n';    // 5

    while (!h.empty()) std::cout << h.pop() << ' ';
    // 1 2 3 4 5
}
```

Pushing in descending order forces every element to bubble all the way up, and popping everything yields the values in **ascending order**. Together these exercise both sift directions and demonstrate the idea behind heap sort.

It also works with other types:

```cpp
MinHeap<double> d;
MinHeap<std::string> s;     // lexicographic order
```

---

# ⚡ Complexity Analysis

| Operation | Time     |
| --------- | :------: |
| Push      | O(log n) |
| Pop       | O(log n) |
| Top       | O(1)     |
| Size      | O(1)     |
| Empty     | O(1)     |

**Space complexity:** O(n)

A complete binary tree with `n` nodes has height `⌊log₂ n⌋`, and both `push` and `pop` move along a single root-to-leaf path. The recursion depth of `heapifyUp` and `heapifyDown` is also O(log n).

---

# 🌍 Real-World Applications

A MinHeap is useful when you repeatedly need the **smallest** item:

- Priority Queues (lowest cost or earliest deadline first)
- Dijkstra's Shortest Path Algorithm
- Prim's Minimum Spanning Tree
- Kth Largest Element (keep a MinHeap of size k)
- Merging K Sorted Lists
- Finding the Median of a Data Stream (upper half in a MinHeap)
- Huffman Coding
- Event-Driven Simulation and Timers

---

# ⚠️ Common Implementation Mistakes

- **Wrong comparison direction:** a MinHeap uses `<` in *both* `heapifyUp` and `heapifyDown`. Mixing `<` and `>` quietly produces a broken heap.
- **Mixing 0-based and 1-based indexing:** `2*i` and `2*i + 1` are for 1-based arrays.
- **Unsigned underflow:** calling `(idx - 1) / 2` when `idx == 0` with `size_t`.
- **Assuming both children exist:** check `left < size` and `right < size` separately. Bailing out when *either* child is missing leaves left-only nodes unfixed.
- **Swapping with the wrong child:** in a MinHeap, sink toward the **smaller** child.
- **Heapifying the whole array on every push** instead of sifting up only from the new element, which turns O(log n) into O(n).
- **Not guarding `pop` on a single element:** after `pop_back()` the vector is empty, so skip `heapifyDown`.
- **Leaving `int` inside a template**, such as `int poppedVal = heap[0];`, which truncates `double` and fails to compile for `std::string`.

Always test the boundaries: empty heap, one element, two elements (left-only child), and duplicates.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

- Move semantics: `push(T&&)` and `std::move` in `pop`
- `const T& top() const` to avoid a copy
- Generic `Compare` parameter (`std::less` / `std::greater`) to unify MinHeap and MaxHeap
- Iterative `heapifyUp` and `heapifyDown`
- Build Heap from a `std::vector` in O(n)
- Heap Sort
- Kth Largest Element in an Array
- Merge K Sorted Lists
- Connect Ropes with Minimum Cost
- Dijkstra's Algorithm with a MinHeap of `(distance, node)` pairs

---

# 📝 Key Takeaways

- A MinHeap is a **complete binary tree** stored in a **vector**.
- The **smallest** element is always at index `0`.
- `push` appends and **sifts up**. `pop` moves the last element to the root and **sifts down**.
- `push` and `pop` are **O(log n)**, and `top` is **O(1)**.
- A heap is **partially ordered**, not sorted.
- A MinHeap is a MaxHeap with every comparison flipped.

---

# 🔗 Related Implementations

↔️ **MaxHeap**: The mirror image, with the largest element at the root.

⬆️ **Heap (parent chapter)**: Overview of heaps, array representation, and complexity.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home
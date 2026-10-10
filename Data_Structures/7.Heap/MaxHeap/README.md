# 🔺 Implementing a MaxHeap

> **"A MaxHeap always keeps the largest element at the top, one step away."**

A **MaxHeap** is a **complete binary tree** in which every parent is **greater than or equal to** its children. This guarantees that the **largest** element is always at the root, so it can be read instantly and removed in logarithmic time.

This implementation is a **generic, array-backed MaxHeap** built on `std::vector<T>`. The tree is never stored with nodes or pointers. Parent and child positions are computed with index arithmetic.

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

- Explain the max-heap property.
- Use index formulas to navigate a tree stored in an array.
- Implement `push` with **heapify up**.
- Implement `pop` with **heapify down**.
- Handle edge cases: empty heap, single element, left-only child.
- Analyze the complexity of each operation.

---

# 📂 Directory Structure

```text
MaxHeap/
├── main.cpp
├── maxheap.h
└── README.md
```

| File         | Purpose                                              |
| ------------ | ---------------------------------------------------- |
| `maxheap.h`  | The templated `MaxHeap<T>` class                     |
| `main.cpp`   | Driver code that exercises the heap                  |
| `README.md`  | This document                                        |

---

# 🧠 The Core Idea

The max-heap property: for every node, `parent >= child`.

```text
MaxHeap as a tree:

            9
          /   \
         7     8
        / \   /
       3   5 4
```

Stored in an array, level by level:

```text
index:  0  1  2  3  4  5
value: [9, 7, 8, 3, 5, 4]
```

Only the parent-to-child relationship is ordered. Siblings have no required order (7 and 8 above), so a heap is **not sorted**. It only guarantees that the maximum is at index `0`.

---

# 🗂️ Index Arithmetic (0-based)

For a node at index `i`:

| Relation    | Formula       |
| ----------- | ------------- |
| Parent      | `(i - 1) / 2` |
| Left child  | `2 * i + 1`   |
| Right child | `2 * i + 2`   |

```text
          i = 1  (value 7)
         /          \
  left = 3 (3)    right = 4 (5)

  parent of 4  →  (4 - 1) / 2 = 1  ✔
```

---

# ⚙️ Supported Operations

| Operation | Description                                   |
| --------- | --------------------------------------------- |
| `push(v)` | Insert a value                                |
| `pop()`   | Remove and return the largest value           |
| `top()`   | Return the largest value without removing it  |
| `size()`  | Number of elements                            |
| `empty()` | Whether the heap has no elements              |

`pop()` and `top()` throw `std::underflow_error` if the heap is empty.

---

# 🏗️ The Implementation

`maxheap.h`:

```cpp
#include<vector>
#include<utility>
#include<stdexcept>

template <typename T>
class MaxHeap {
private:
    std::vector<T> heap;
    void heapifyUp(size_t idx) {
        if(!idx) return;
        size_t p=(idx-1)/2;
        if(heap[idx]>heap[p]) {
            std::swap(heap[idx],heap[p]);
            heapifyUp(p);
        }
    }
    void heapifyDown(size_t idx) {
        size_t left=idx*2+1;
        size_t right=idx*2+2;
        size_t target=idx;
        if(left<heap.size() && heap[left]>heap[target])   target=left;
        if(right<heap.size() && heap[right]>heap[target]) target=right;
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
        if(heap.empty()) throw std::underflow_error("MaxHeap is empty");
        T poppedVal=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        if(!heap.empty()) heapifyDown(0);
        return poppedVal;
    }
    T top() const {
        if(heap.empty()) throw std::underflow_error("MaxHeap is empty");
        return heap[0];
    }
    size_t size() const { return heap.size(); }
    bool empty() const { return heap.empty(); }
};
```

**Requirement on `T`:** it must support `operator>`, be copy-constructible, and be copy-assignable.

---

# 🔨 Push (Heapify Up)

The new value is appended at the end, which keeps the tree complete. If it is larger than its parent, it **bubbles up** by swapping until its parent is greater or it reaches the root.

Before:

```text
        9
       / \
      7   8
```

Execute:

```cpp
push(10);
```

Step 1: append at the end.

```text
        9
       / \
      7   8
     /
   (10)          ← 10 > parent (7), swap
```

Step 2: keep swapping upward.

```text
        10
       /  \
      9    8
     /
    7
```

**Base case:** `if(!idx) return;` runs *before* the parent is computed. With `size_t`, `(0 - 1) / 2` would wrap around to a huge number.

---

# 🔨 Pop (Heapify Down)

The root holds the maximum. To remove it while keeping the tree complete:

1. Save the root value to return it.
2. Move the **last** element into the root.
3. Remove the last slot with `pop_back()`.
4. **Sink** the new root down until it is no smaller than both children.

Before:

```text
        10
       /  \
      9    8
     / \
    7   5
```

Execute:

```cpp
pop();    // returns 10
```

Step 1: move the last element (5) to the root.

```text
         5
       /  \
      9    8
     /
    7           ← 5 < larger child (9), swap
```

Step 2: swap with the **larger** child until the heap property holds.

```text
         9
       /  \
      7    8
     /
    5
```

In `heapifyDown`, `target` starts as the node itself, then becomes the left child if it is larger, then the right child if it is larger still. By the end, `target` is the largest of the three. Each child's bounds are checked **independently**, so a node with only a left child is handled safely.

---

# 🧪 Example Usage

```cpp
#include <iostream>
#include "maxheap.h"

int main() {
    MaxHeap<int> h;
    for (int x : {3, 1, 4, 1, 5, 9, 2, 6}) h.push(x);

    std::cout << "Top: " << h.top() << '\n';      // 9
    std::cout << "Size: " << h.size() << '\n';    // 8

    while (!h.empty()) std::cout << h.pop() << ' ';
    // 9 6 5 4 3 2 1 1
}
```

Popping everything yields the values in **descending order**, which is the idea behind heap sort.

It also works with other types:

```cpp
MaxHeap<double> d;
MaxHeap<std::string> s;     // lexicographic order
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

A MaxHeap is useful when you repeatedly need the **largest** item:

- Priority Queues (highest priority first)
- Heap Sort (ascending order)
- Kth Smallest Element (keep a MaxHeap of size k)
- Task Scheduling by Priority
- Finding the Median of a Data Stream (lower half in a MaxHeap)
- Top-K Problems
- Event Simulation

---

# ⚠️ Common Implementation Mistakes

- **Wrong comparison direction:** a MaxHeap uses `>` in *both* `heapifyUp` and `heapifyDown`. Mixing `<` and `>` quietly produces a broken heap.
- **Mixing 0-based and 1-based indexing:** `2*i` and `2*i + 1` are for 1-based arrays.
- **Unsigned underflow:** calling `(idx - 1) / 2` when `idx == 0` with `size_t`.
- **Assuming both children exist:** check `left < size` and `right < size` separately.
- **Swapping with the wrong child:** in a MaxHeap, sink toward the **larger** child.
- **Not guarding `pop` on a single element:** after `pop_back()` the vector is empty, so skip `heapifyDown`.
- **Using `int` instead of `T` inside the template**, which truncates `double` and breaks `std::string`.

Always test the boundaries: empty heap, one element, two elements (left-only child), and duplicates.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

- Move semantics: `push(T&&)` and `std::move` in `pop`
- `const T& top() const` to avoid a copy
- Generic `Compare` parameter (`std::less` / `std::greater`) to unify MaxHeap and MinHeap
- Iterative `heapifyUp` and `heapifyDown`
- Build Heap from a `std::vector` in O(n)
- Heap Sort
- Kth Largest Element in an Array
- Last Stone Weight
- Top K Frequent Elements
- Find Median from Data Stream (with a MinHeap)

---

# 📝 Key Takeaways

- A MaxHeap is a **complete binary tree** stored in a **vector**.
- The **largest** element is always at index `0`.
- `push` appends and **sifts up**. `pop` moves the last element to the root and **sifts down**.
- `push` and `pop` are **O(log n)**, and `top` is **O(1)**.
- A heap is **partially ordered**, not sorted.
- A MaxHeap is a MinHeap with every comparison flipped.

---

# 🔗 Related Implementations

↔️ **MinHeap**: The mirror image, with the smallest element at the root.

⬆️ **Heap (parent chapter)**: Overview of heaps, array representation, and complexity.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home
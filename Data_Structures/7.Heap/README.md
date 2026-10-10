# ⛰️ Implementing a Heap (Min & Max with a Comparator)

> **"A heap keeps the most important element always one step away, at the top, and you decide what 'important' means."**

A **Heap** is a specialized **complete binary tree** that satisfies the **heap property**. It is the data structure behind **priority queues**, letting you repeatedly retrieve the "best" element efficiently.

This chapter implements a **single generic `Heap<T, Compare>` class** that behaves as a **MinHeap** or a **MaxHeap** depending on the comparator you pass in:

- **MinHeap:** the **smallest** element is at the root (`std::less<T>`, the default).
- **MaxHeap:** the **largest** element is at the root (`std::greater<T>`).

Although a heap is conceptually a tree, it is stored in a plain **array (`std::vector`)**, with no pointers or nodes required.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

- Vectors (Dynamic Arrays)
- Binary Trees
- Recursion
- Templates (Generic Programming)
- Pointers
- Function Objects (Functors)
- Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

- Understand the heap property and the complete-tree shape.
- Map a binary tree onto an array using index arithmetic.
- Implement `push` using **heapify up** (sift up).
- Implement `pop` using **heapify down** (sift down).
- Use a **comparator template parameter** to get both a MinHeap and a MaxHeap from one class.
- Write custom comparators for pointers and structs.
- Analyze the complexity of heap operations.

---

# 📂 Directory Structure

```text
7.Heaps/
├── heap.h
├── main.cpp
└── README.md
```

| File        | Purpose                                                    |
| ----------- | ---------------------------------------------------------- |
| `heap.h`    | The templated `Heap<T, Compare>` class                     |
| `main.cpp`  | Driver with Min/Max heaps of `int` and of `Node*`          |
| `README.md` | This document                                              |

---

# 🧠 The Core Idea

A heap has two defining rules:

1. **Shape property:** the tree is *complete*. Every level is full except possibly the last, which is filled from left to right.
2. **Heap property:** every parent is ordered relative to its children. For a MinHeap, `parent <= child`. For a MaxHeap, `parent >= child`.

```text
MinHeap as a tree:

            1
          /   \
         3     2
        / \   /
       7   4 5
```

Only parent-to-child ordering is guaranteed. Siblings and cousins have **no** ordering between them, so a heap is **not** a sorted structure.

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

> ⚠️ If you use **1-based** indexing instead, the formulas become `i / 2`, `2i`, and `2i + 1`. Pick one convention and use it everywhere.

---

# ⚙️ Supported Operations

| Operation               | Description                                        |
| ----------------------- | -------------------------------------------------- |
| `Heap()`                | Create an empty heap                               |
| `Heap(vector<T>)`       | Create a heap from an existing vector of values    |
| `push(v)`               | Insert a value                                     |
| `pop()`                 | Remove and return the top (best) value             |
| `top()`                 | Return the top value without removing it           |
| `size()`                | Number of elements                                 |
| `empty()`               | Whether the heap has no elements                   |

`pop()` and `top()` throw `std::underflow_error` if the heap is empty.

There is no random access and no search. The heap exists to answer one question quickly: *"what is the best element right now?"*

---

# 🔀 The Comparator: One Class, Two Heaps

The previous design used two nearly identical classes, `MinHeap` and `MaxHeap`, that differed only in the direction of their comparisons. Here the comparison is a **template parameter**, so one class covers both.

```cpp
template <typename T, typename Compare = std::less<T>>
class Heap {
    Compare compare;   // compare(a, b) is true if a should sit above b
    ...
};
```

Every place the old code wrote `heap[i] < heap[j]` or `heap[i] > heap[j]` now calls `compare(heap[i], heap[j])`.

| Declaration                       | `compare(a, b)` means | Result  |
| --------------------------------- | --------------------- | ------- |
| `Heap<int>`                       | `a < b`               | MinHeap |
| `Heap<int, std::less<int>>`       | `a < b`               | MinHeap |
| `Heap<int, std::greater<int>>`    | `a > b`               | MaxHeap |

### How can a member be "called"?

`std::less<T>` and `std::greater<T>` (from `<functional>`) are small structs that define `operator()`, so their objects can be called like functions:

```cpp
template <typename T>
struct less {
    bool operator()(const T& a, const T& b) const { return a < b; }
};
```

The member `Compare compare;` is default-constructed when the heap is created, so you never initialize it yourself.

### Heads-up: the defaults differ from `std::priority_queue`

| Container                                  | Default order | To get the other one |
| ------------------------------------------ | ------------- | -------------------- |
| `Heap<T>` (this implementation)            | **Min**-heap  | pass `std::greater<T>` |
| `std::priority_queue<T>` (STL)             | **Max**-heap  | pass `std::greater<T>` as the 3rd argument |

`std::priority_queue` interprets its comparator as "a has *lower* priority than b," which is the opposite of this class. Be careful when switching between the two.

---

# 🏗️ The Implementation

`heap.h`:

```cpp
#include<vector>
#include<utility>
#include<stdexcept>
#include<functional>

template <typename T,typename Compare=std::less<T>>
class Heap {
private:
    std::vector<T> heap;
    Compare compare;
    void heapifyUp(size_t idx) {
        if(!idx) return;
        size_t parent=(idx-1)/2;
        if(compare(heap[idx],heap[parent])) {
            std::swap(heap[idx],heap[parent]);
            heapifyUp(parent);
        }
    }
    void heapifyDown(size_t idx) {
        size_t left=idx*2+1;
        size_t right=idx*2+2;
        size_t target=idx;
        if(left<heap.size() && compare(heap[left],heap[target]))   target=left;
        if(right<heap.size() && compare(heap[right],heap[target])) target=right;
        if(target!=idx) {
            std::swap(heap[idx],heap[target]);
            heapifyDown(target);
        }
    }
public:
    Heap() {}
    Heap(const std::vector<T>& vals) {
        for(size_t idx=0;idx<vals.size();idx++) push(vals[idx]);
    }
    void push(const T& val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }
    T pop() {
        if(heap.empty()) throw std::underflow_error("Heap is empty");
        T poppedVal=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        if(!heap.empty()) heapifyDown(0);
        return poppedVal;
    }
    T top() const {
        if(heap.empty()) throw std::underflow_error("Heap is empty");
        return heap[0];
    }
    size_t size() const { return heap.size(); }
    bool empty() const { return heap.empty(); }
};
```

**Requirements on `T` and `Compare`:** `T` must be copy-constructible and copy-assignable. `Compare` must be callable with two `const T&` arguments and return `bool`, and it must be default-constructible. Declaring its `operator()` as `const` is good practice.

---

# 🧱 Constructing from a Vector

```cpp
Heap(const std::vector<T>& vals) {
    for(size_t idx=0;idx<vals.size();idx++) push(vals[idx]);
}
```

This constructor inserts each value with `push`, so building a heap from `n` values costs **O(n log n)**. A dedicated *build-heap* routine can do it in **O(n)** (see the exercises).

Because the parameter is a `const std::vector<T>&`, a brace list works directly:

```cpp
Heap<int> h({3, 4, 5, 1, 2});
```

---

# 🔨 Push (Heapify Up)

New elements are appended at the end of the array, which keeps the tree complete. That may break the heap property, so the element **bubbles up** while `compare(child, parent)` is true.

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
    1          ← compare(1, 5) is true, swap
```

Step 2: keep swapping with the parent until `compare` is false or the root is reached.

```text
        1
       / \
      2   3
     /
    5
```

**Base case:** `if(!idx) return;` runs *before* the parent is computed. With `size_t`, `(0 - 1) / 2` would wrap around to a huge number.

At most one swap per level, so push is **O(log n)**.

---

# 🔨 Pop (Heapify Down)

The root is the element being removed. To keep the tree complete:

1. Save the root value to return it.
2. Move the **last** element into the root.
3. Remove the last slot with `pop_back()`.
4. **Sink** the new root down until no child should sit above it.

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
pop();    // returns 1
```

Step 1: move the last element (4) to the root and shrink the array.

```text
        4
       / \
      2   3
     /
    5            ← compare(2, 4) is true, swap
```

Step 2: swap with the child that should sit highest until none does.

```text
        2
       / \
      4   3
     /
    5
```

In `heapifyDown`, `target` starts as the node itself. It becomes the left child if `compare(left, target)` is true, then the right child if `compare(right, target)` is true. By the end, `target` is the "best" of the three, whether that means smallest (MinHeap) or largest (MaxHeap). Each child's bounds are checked **separately**, so a node with only a left child is handled correctly.

Pop is **O(log n)**.

---

# 🧪 Example Usage

`main.cpp` builds Min and Max heaps of `int` and of `Node*`, then pops each one until it is empty.

### Heaps of `int`

```cpp
vector<int> vals={3,4,5,1,2};
Heap<int,less<int>>    minHeap;
Heap<int,greater<int>> maxHeap;
for(int val:vals) {
    minHeap.push(val);
    maxHeap.push(val);
}
while(!minHeap.empty()) cout<<minHeap.pop()<<' ';   // 1 2 3 4 5
while(!maxHeap.empty()) cout<<maxHeap.pop()<<' ';   // 5 4 3 2 1
```

Popping everything yields the values in sorted order, which is the idea behind heap sort.

### Heaps of `Node*` with custom comparators

A heap can also hold pointers, as long as the comparator says how to order them.

```cpp
struct Node {
    int val;
    Node* next;
    Node(int _val): val(_val), next(nullptr) {}
};

// MinHeap of Node*: smaller val on top
struct MinCompare {
    bool operator()(Node* a,Node* b) const { return a->val < b->val; }
};
// MaxHeap of Node*: larger val on top
struct MaxCompare {
    bool operator()(Node* a,Node* b) const { return a->val > b->val; }
};

vector<Node*> nodes;
for(int val:vals) nodes.push_back(new Node(val));

Heap<Node*,MinCompare> minHeapNode;
Heap<Node*,MaxCompare> maxHeapNode;
for(Node* node:nodes) {
    minHeapNode.push(node);
    maxHeapNode.push(node);
}
while(!minHeapNode.empty()) cout<<minHeapNode.pop()->val<<' ';   // 1 2 3 4 5
while(!maxHeapNode.empty()) cout<<maxHeapNode.pop()->val<<' ';   // 5 4 3 2 1

for(Node*& node:nodes) delete node;
```

Output:

```text
Min Heap on int  : [1,2,3,4,5]
Max Heap of int  : [5,4,3,2,1]
Min Heap of Node*: [1,2,3,4,5]
Max Heap of Node*: [5,4,3,2,1]
```

Two points worth noticing:

- **Compare by value, not address.** With the default `std::less<Node*>`, the heap would order nodes by their **memory addresses**, which is almost never what you want. `MinCompare` and `MaxCompare` compare `a->val` and `b->val` instead.
- **The heap does not own the pointers.** Each node is pushed into two heaps, so the `nodes` vector is the single owner and deletes each node exactly once. Popping a pointer from a heap does not free it.

> 💡 **Lambdas:** before C++20, a lambda type cannot be default-constructed, so `Heap<Node*, decltype(cmp)>` will not compile with the current class. Adding a constructor that accepts the comparator (see the exercises) fixes this.

---

# 📊 Relationship with Other Data Structures

```text
        Complete Binary Tree
                 |
         Heap<T, Compare>
              /      \
        std::less   std::greater
        (MinHeap)    (MaxHeap)
              \      /
          Priority Queue
```

- A heap is a **complete binary tree** stored in an array.
- A **priority queue** is the abstract idea. A heap is the most common way to implement it.
- `std::priority_queue` is built on exactly this idea, using `std::vector` and a comparator.

---

# ⚡ Complexity Analysis

| Operation                             | Time      |
| ------------------------------------- | :-------: |
| Push                                  | O(log n)  |
| Pop                                   | O(log n)  |
| Top                                   | O(1)      |
| Size                                  | O(1)      |
| Empty                                 | O(1)      |
| Construct from vector (`n` pushes)    | O(n log n) |
| Build Heap (dedicated routine)        | O(n)      |

**Space complexity:** O(n)

Both `push` and `pop` travel along a single root-to-leaf path, and the height of a complete binary tree with `n` nodes is `⌊log₂ n⌋`. The recursion depth of `heapifyUp` and `heapifyDown` is also O(log n).

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
- Merging K Sorted Linked Lists (a heap of `Node*`)

A **MinHeap** fits "smallest or earliest first" problems. A **MaxHeap** fits "largest or highest-priority first" problems.

---

# ⚠️ Common Implementation Mistakes

When implementing a heap, beginners often:

- **Mix 0-based and 1-based indexing**, for example using `2*i` and `2*i + 1` on a 0-based vector.
- **Underflow the parent index:** `(0 - 1) / 2` with `size_t` wraps to a huge number. Check for the root *before* computing the parent.
- **Read a missing child:** a node can have a left child but no right child. Check `left < size` and `right < size` independently.
- **Heapify the whole array on every push** instead of sifting up only from the new element (this turns O(log n) into O(n)).
- **Forget the single-element case in `pop`:** after `pop_back()` the heap may be empty, so skip `heapifyDown`.
- **Leave a hard-coded `int` inside a template**, such as `int poppedVal = heap[0];`, which silently truncates `double` and fails to compile for `std::string`.
- **Mix up comparator direction:** `std::less` gives a MinHeap here but a MaxHeap in `std::priority_queue`.
- **Write a non-strict comparator:** use `<` or `>`, not `<=` or `>=`. Non-strict comparisons cause needless swaps of equal elements.
- **Order pointers by address:** `Heap<Node*>` with the default comparator compares addresses, not the values they point to. Supply a comparator that dereferences.
- **Delete popped pointers twice, or never:** the heap stores pointers but does not own them. Decide who owns each object and free it exactly once.

Testing boundary conditions (empty, one element, two elements, left-only child, duplicates) is essential for a reliable implementation.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

- A constructor that accepts the comparator, `explicit Heap(Compare c) : compare(c) {}`, so lambdas work
- Build Heap from a `std::vector` in O(n) by running `heapifyDown` from the last parent to the root
- Move semantics: `push(T&&)` and `std::move` in `pop`
- `const T& top() const` to avoid a copy
- Iterative `heapifyUp` / `heapifyDown`
- Heap Sort
- Kth Largest Element in an Array
- Merge K Sorted Linked Lists (a heap of `Node*` is already set up in `main.cpp`)
- Find Median from Data Stream
- Dijkstra's Algorithm with a heap of `(distance, node)` pairs

---

# 📝 Key Takeaways

- A heap is a **complete binary tree** stored in a **contiguous array**.
- The root always holds the "best" element according to the comparator.
- `compare(a, b)` means **"a should sit above b."**
- `std::less<T>` gives a **MinHeap** and `std::greater<T>` gives a **MaxHeap**.
- For pointers or structs, write a custom comparator that compares the fields you care about.
- `push` appends and **sifts up**. `pop` moves the last element to the root and **sifts down**.
- `push` and `pop` run in **O(log n)**, and `top` runs in **O(1)**.
- A heap is **not sorted**, only partially ordered. It guarantees the top element and nothing else.

---

# 🔗 Related Implementations

⬅️ **Binary Tree**: Introduces hierarchical data structures and recursive traversal, the foundation for the heap's tree shape.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home
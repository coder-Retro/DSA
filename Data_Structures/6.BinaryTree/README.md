# 🌳 Building Binary Trees

> **"A binary tree is a hierarchical data structure in which each node has at most two children, commonly referred to as the left child and the right child."**

Unlike linear data structures such as vectors, linked lists, stacks, and queues, binary trees organize data hierarchically. Every node can branch into two subtrees, making binary trees ideal for representing hierarchical relationships.

This chapter introduces the **general binary tree**: its structure, terminology, traversals, and the complexity of common operations. Two specialized, ordered trees build on these ideas and each has its own implementation folder:

- **Binary Search Tree (BST)**, which adds an ordering property for fast searching.
- **AVL Tree**, a BST that rebalances itself with rotations so its height always stays logarithmic.

---

# 📖 Prerequisites

Before studying these implementations, you should understand:

- Pointers
- Classes & Objects
- Dynamic Memory Allocation (`new` / `delete`)
- Recursion
- Linked Lists

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

- Understand hierarchical data structures.
- Implement binary tree nodes.
- Build a binary tree manually.
- Traverse a tree using recursion.
- Understand common tree terminology.
- Analyze the complexity of tree operations.
- Explain how a BST uses ordering to speed up search.
- Explain why an unbalanced BST degrades to O(n).
- Understand how an AVL tree uses balance factors and rotations to stay balanced.

---

# 📂 Directory Structure

```text
6.BinaryTree/
├── AVL/
│   ├── main.cpp
│   ├── README.md
│   └── tree.h
├── BST/
│   ├── main.cpp
│   ├── README.md
│   └── tree.h
└── README.md
```

| Folder | Contents |
| ------ | -------- |
| `BST/` | Binary Search Tree implementation and tests |
| `AVL/` | Self-balancing AVL Tree implementation and tests |

---

# 🧠 The Core Idea

Unlike arrays or linked lists, a binary tree stores data in a hierarchy.

```text
             Root
              │
        ┌─────┴─────┐
        │           │
      Left       Right
      Child      Child
```

Each node can have:

- Zero children
- One child
- Two children

---

# 🏗️ Internal Representation

A typical node contains:

```cpp
struct Node {
    T data;
    Node* left;
    Node* right;
};
```

Each node stores:

- Data
- Pointer to the left child
- Pointer to the right child

Specialized trees extend this node. An AVL node, for example, also stores its **height**:

```cpp
struct Node {
    T val;
    int height;   // used to compute the balance factor in O(1)
    Node* left;
    Node* right;
};
```

---

# 🌱 Example Binary Tree

```text
          10
         /  \
       20    30
      / \      \
    40  50     60
```

Unlike a Binary Search Tree, there are **no ordering rules** in a general binary tree.

---

# 📚 Tree Terminology

| Term           | Meaning                                                      |
| -------------- | ------------------------------------------------------------ |
| Root           | Top-most node                                                |
| Parent         | Node with children                                           |
| Child          | Node connected below a parent                                |
| Leaf           | Node with no children                                        |
| Sibling        | Nodes sharing the same parent                                |
| Height         | Longest path from root to leaf                               |
| Depth          | Distance from root to a node                                 |
| Subtree        | Tree rooted at any node                                      |
| Balance Factor | Height of left subtree minus height of right subtree         |
| Rotation       | Local pointer rearrangement that preserves in-order sequence |

Understanding these terms makes discussing tree algorithms much easier.

> **Note on height:** some texts count nodes on the longest path (a single node has height 1), others count edges (a single node has height 0). Pick one convention and stay consistent. The AVL implementation here uses height 1 for a leaf and 0 for an empty subtree.

---

# 🔄 Tree Traversals

Traversal means visiting every node in a specific order.

### Inorder (Left → Root → Right)

```text
Left
 ↓
Root
 ↓
Right
```

In a BST or AVL tree, an inorder traversal returns the values in **sorted order**.

---

### Preorder (Root → Left → Right)

```text
Root
 ↓
Left
 ↓
Right
```

---

### Postorder (Left → Right → Root)

```text
Left
 ↓
Right
 ↓
Root
```

---

### Level Order (Breadth-First)

Visits nodes level by level, from top to bottom, using a queue.

Each traversal has different applications depending on the problem.

---

# 🌲 Specialized Binary Trees

## Binary Search Tree (BST)

A BST adds one rule: for every node, all values in the **left subtree are smaller** and all values in the **right subtree are larger**.

```text
          50
         /  \
       30    70
      / \   /  \
    20  40 60  80
```

This lets search, insert, and delete discard half of the remaining tree at each step, **if the tree is balanced**. If values are inserted in sorted order, a BST degenerates into a linked list:

```text
1
 \
  2
   \
    3
     \
      4      →  height n, operations cost O(n)
```

➡️ See [`BST/`](BST/) for the implementation.

---

## AVL Tree

An AVL tree is a BST that maintains one extra invariant: for every node, the heights of its left and right subtrees differ by **at most 1**.

```text
balance factor = height(left) − height(right) ∈ { −1, 0, +1 }
```

After every insert or delete, the tree walks back up the path it took, updates heights, and fixes any node whose balance factor reaches ±2 using **rotations**.

```text
Right rotation (fixes left-heavy):

      y                x
     / \              / \
    x   C    ===>    A   y
   / \                  / \
  A   B                B   C
```

Rotations only rewire a few pointers, so the in-order sequence (and therefore the BST property) is preserved.

| Case        | Node's balance | Heavy child's balance | Fix                                                |
| ----------- | :------------: | :-------------------: | -------------------------------------------------- |
| Left-Left   |      > 1       |         ≥ 0           | Right rotation on node                             |
| Left-Right  |      > 1       |         < 0           | Left rotation on child, then right rotation on node |
| Right-Right |     < −1       |         ≤ 0           | Left rotation on node                              |
| Right-Left  |     < −1       |         > 0           | Right rotation on child, then left rotation on node |

Because the height is guaranteed to be at most about 1.44 × log₂(n), every operation stays **O(log n)** no matter what order the data arrives in.

➡️ See [`AVL/`](AVL/) for the implementation.

---

# ⚡ Complexity Analysis

### General Binary Tree

| Operation |           Time            |
| --------- | :-----------------------: |
| Traversal |           O(n)            |
| Search    |           O(n)            |
| Insert    | Depends on implementation |
| Delete    | Depends on implementation |

Since a general binary tree has no ordering property, searching may require visiting every node.

### BST vs AVL

| Operation | BST (average) | BST (worst) |    AVL (worst)    |
| --------- | :-----------: | :---------: | :---------------: |
| Search    |   O(log n)    |    O(n)     |     O(log n)      |
| Insert    |   O(log n)    |    O(n)     |     O(log n)      |
| Delete    |   O(log n)    |    O(n)     |     O(log n)      |
| Traversal |     O(n)      |    O(n)     |       O(n)        |
| Space     |     O(n)      |    O(n)     | O(n), plus 1 int per node |

The trade-off: an AVL tree does a little extra work on every insert and delete (updating heights and occasionally rotating) in exchange for a guaranteed logarithmic height.

An insert needs **at most one** rotation (single or double). A delete may trigger rotations at **several** ancestors on the way back up, which is still O(log n) in total.

---

# 🌍 Real-World Applications

Binary Trees are used in:

- File Systems
- Expression Trees
- Decision Trees
- XML / HTML DOM
- Organization Charts
- Game AI
- Compiler Syntax Trees

Balanced search trees such as AVL trees are used in:

- Ordered maps and sets (the idea behind `std::map` and `std::set`)
- In-memory indexes and databases
- Scheduling and event queues that need sorted order with fast updates
- Any workload where worst-case lookup time matters

---

# ⚠️ Common Implementation Mistakes

When implementing binary trees, beginners often:

- Forget to initialize child pointers.
- Lose subtrees while updating pointers.
- Misuse recursion.
- Leak dynamically allocated nodes.
- Fail to handle empty trees.

When implementing an AVL tree specifically, watch for:

- **Stale heights.** Forgetting to call `updateHeight` after a rotation, after a recursive insert/delete, or when building a tree from sorted data. The tree still returns correct answers but silently stops being balanced.
- **Wrong height update order in rotations.** The node that ends up lower must be updated first.
- **Wrong double-rotation condition.** In the double-rotation case, the child's balance factor has the opposite sign from the node's.
- **Single rotation after a delete.** A heavy child with balance factor 0 can occur after a delete and needs a single rotation, not a double one.
- **Rebalancing only once after a delete.** Every ancestor on the path back up must be checked.
- **Shallow copies.** Copying the root pointer instead of rebuilding the tree causes a double free.
- **Duplicates.** Decide how duplicates are handled and keep `size()` consistent.

Always test:

- Empty trees
- Single-node trees
- Left-skewed trees
- Right-skewed trees
- Complete trees
- All four AVL rotation cases (insert `3,2,1`, `3,1,2`, `1,2,3`, `1,3,2`)
- Sorted insertion of many values (an AVL tree's height should stay near log₂ n)
- Random inserts and deletes, validating the tree after every operation

---

# 🧪 Validating an AVL Tree

AVL bugs are silent: a stale height or a slightly wrong rotation does not crash anything, and `contains` and `inOrder` still behave correctly. A validator is the only reliable way to catch them. A good one checks three things for every node:

1. **BST order**, using an allowed `(lo, hi)` range passed down the recursion.
2. **Stored heights** match the real heights.
3. **Balance factor** is within `[-1, +1]`.

Call it after every operation in a randomized stress test, and also check that `size()` equals `inOrder().size()`.

---

# 🎯 Suggested Exercises

After completing these implementations, try adding:

- Count Nodes
- Count Leaf Nodes
- Height of Tree
- Diameter of Tree
- Mirror Tree
- Lowest Common Ancestor
- Level Order Traversal

For the BST and AVL tree:

- Floor and ceiling of a value
- k-th smallest element
- Range query (all values between `lo` and `hi`)
- Move constructor and move assignment
- An iterator over the tree
- A validity checker such as `isValidBST()` or `isValidAVL()`
- Compare BST and AVL heights after inserting `1..n` in sorted order

---

# 📝 Key Takeaways

- Binary trees organize data hierarchically.
- Every node has at most two children.
- Traversals are fundamental tree operations.
- General binary trees do not enforce any ordering of values.
- A BST adds an ordering rule that makes search fast, but only while the tree stays balanced.
- An AVL tree keeps a BST balanced by tracking heights and applying rotations, guaranteeing O(log n) operations.
- Rotations change the shape of a tree without changing its in-order sequence.
- Binary trees provide the foundation for many advanced tree structures.

---

# 🔗 Related Implementations

➡️ **[Binary Search Tree](BST/)**: A specialized binary tree with an ordering property.

➡️ **[AVL Tree](AVL/)**: A self-balancing binary search tree with guaranteed O(log n) operations.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home
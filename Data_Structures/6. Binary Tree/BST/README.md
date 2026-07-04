# 🌲 Building a Binary Search Tree (BST)

> **"A Binary Search Tree (BST) is a binary tree that maintains an ordering property, allowing efficient searching, insertion, and deletion."**

A Binary Search Tree is a specialized form of a binary tree where every node follows a simple but powerful rule:

* Every value in the **left subtree** is smaller than the current node.
* Every value in the **right subtree** is greater than the current node.

This ordering transforms a regular binary tree into an efficient searching data structure.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

* Binary Trees
* Recursion
* Pointers
* Dynamic Memory Allocation
* Tree Traversals

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand the BST property.
* Search efficiently.
* Insert new nodes.
* Delete nodes correctly.
* Find minimum and maximum values.
* Analyze balanced and unbalanced trees.

---

# 📂 Directory Structure

```text
BST/
├── BST.cpp
└── README.md
```

---

# 🌱 BST Property

For every node:

```text
Left Subtree  <  Root  <  Right Subtree
```

Example:

```text
          50
         /  \
       30    70
      / \    / \
    20 40  60 80
```

This ordering is preserved after every insertion and deletion.

---

# 🔨 Search Operation

Searching begins at the root.

```text
Searching for 60

      50
        \
         70
        /
      60
```

Comparison determines whether to move left or right.

This avoids searching unnecessary nodes.

---

# ➕ Insertion

To insert a new value:

1. Start at the root.
2. Compare with the current node.
3. Move left if smaller.
4. Move right if larger.
5. Insert when a null child is reached.

The BST property remains intact after insertion.

---

# ❌ Deletion

Deleting a node has three possible cases:

### Case 1 — Leaf Node

Simply remove it.

---

### Case 2 — One Child

Replace the node with its child.

---

### Case 3 — Two Children

Replace the node with its:

* Inorder Successor **or**
* Inorder Predecessor

Then remove the duplicate node.

---

# 🔄 Traversals

BSTs support the same traversals as binary trees.

However, **Inorder Traversal** has a unique property:

```text
Inorder Traversal

↓

Sorted Order
```

This makes BSTs useful for maintaining ordered data.

---

# ⚡ Complexity Analysis

| Operation |  Average | Worst |
| --------- | :------: | :---: |
| Search    | O(log n) |  O(n) |
| Insert    | O(log n) |  O(n) |
| Delete    | O(log n) |  O(n) |

Worst-case performance occurs when the tree becomes heavily skewed.

---

# 🌍 Real-World Applications

Binary Search Trees are used in:

* Ordered Dictionaries
* Symbol Tables
* In-Memory Databases
* File Indexing
* Range Queries
* Auto-Completion Systems
* Compiler Data Structures

Balanced variants such as AVL Trees and Red-Black Trees are widely used in production systems.

---

# ⚠️ Common Implementation Mistakes

When implementing a BST, beginners often:

* Violate the BST ordering property.
* Forget to reconnect subtrees after deletion.
* Mishandle the two-child deletion case.
* Ignore duplicate values.
* Leak memory after removing nodes.

Testing all deletion scenarios is essential.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

* Find Minimum
* Find Maximum
* Validate BST
* kth Smallest Element
* Lowest Common Ancestor
* AVL Tree
* Red-Black Tree

These exercises naturally extend the concepts introduced in this chapter.

---

# 📝 Key Takeaways

* A BST is a specialized binary tree with an ordering property.
* Efficient searching is achieved by comparing values and traversing only one subtree at each step.
* Insertions and deletions preserve the BST property.
* Balanced BSTs provide logarithmic performance for common operations.
* Understanding BSTs lays the groundwork for advanced self-balancing trees.

---

# 🔗 Related Implementations

⬅️ **Binary Tree** — Provides the hierarchical foundation for BSTs.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home

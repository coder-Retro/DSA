# 🌳 Building Binary Trees

> **"A binary tree is a hierarchical data structure in which each node has at most two children, commonly referred to as the left child and the right child."**

Unlike linear data structures such as vectors, linked lists, stacks, and queues, binary trees organize data hierarchically. Every node can branch into two subtrees, making binary trees ideal for representing hierarchical relationships.

This chapter focuses on implementing a **general binary tree**, understanding its structure, traversing its nodes, and analyzing common operations. The Binary Search Tree (BST), a specialized form of binary tree, is covered separately.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

* Pointers
* Classes & Objects
* Dynamic Memory Allocation (`new` / `delete`)
* Recursion
* Linked Lists

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand hierarchical data structures.
* Implement binary tree nodes.
* Build a binary tree manually.
* Traverse a tree using recursion.
* Understand common tree terminology.
* Analyze the complexity of tree operations.

---

# 📂 Directory Structure

```text
Binary Tree/
├── BinaryTree.cpp
├── BST/
└── README.md
```

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

* Zero children
* One child
* Two children

---

# 🏗️ Internal Representation

A typical node contains:

```cpp
class Node
{
public:
    int data;
    Node* left;
    Node* right;
};
```

Each node stores:

* Data
* Pointer to the left child
* Pointer to the right child

---

# 🌱 Example Binary Tree

```text
          10
         /  \
       20    30
      / \      \
    40  50     60
```

Unlike a Binary Search Tree, there are **no ordering rules**.

---

# 📚 Tree Terminology

| Term    | Meaning                        |
| ------- | ------------------------------ |
| Root    | Top-most node                  |
| Parent  | Node with children             |
| Child   | Node connected below a parent  |
| Leaf    | Node with no children          |
| Sibling | Nodes sharing the same parent  |
| Height  | Longest path from root to leaf |
| Depth   | Distance from root to a node   |
| Subtree | Tree rooted at any node        |

Understanding these terms makes discussing tree algorithms much easier.

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

Each traversal has different applications depending on the problem.

---

# ⚡ Complexity Analysis

| Operation |            Time           |
| --------- | :-----------------------: |
| Traversal |            O(n)           |
| Search    |            O(n)           |
| Insert    | Depends on implementation |
| Delete    | Depends on implementation |

Since a general binary tree has no ordering property, searching may require visiting every node.

---

# 🌍 Real-World Applications

Binary Trees are used in:

* File Systems
* Expression Trees
* Decision Trees
* XML / HTML DOM
* Organization Charts
* Game AI
* Compiler Syntax Trees

---

# ⚠️ Common Implementation Mistakes

When implementing binary trees, beginners often:

* Forget to initialize child pointers.
* Lose subtrees while updating pointers.
* Misuse recursion.
* Leak dynamically allocated nodes.
* Fail to handle empty trees.

Always test:

* Empty trees
* Single-node trees
* Left-skewed trees
* Right-skewed trees
* Complete trees

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

* Count Nodes
* Count Leaf Nodes
* Height of Tree
* Diameter of Tree
* Mirror Tree
* Lowest Common Ancestor
* Level Order Traversal

---

# 📝 Key Takeaways

* Binary trees organize data hierarchically.
* Every node has at most two children.
* Traversals are fundamental tree operations.
* General binary trees do not enforce any ordering of values.
* Binary trees provide the foundation for many advanced tree structures.

---

# 🔗 Related Implementations

➡️ **Binary Search Tree** — A specialized binary tree with an ordering property.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home

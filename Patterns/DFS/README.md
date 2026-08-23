# 🌲 Depth First Search (DFS) Pattern

> **"Explore as far as possible down one branch before backtracking to explore the next."**

Depth First Search is a fundamental traversal technique used whenever a problem branches into multiple paths and the solution requires fully exploring one path before moving to the next. It is the backbone of tree traversals, graph exploration, and backtracking algorithms.

DFS is closely tied to **Recursion**—most DFS implementations are recursive by nature, relying on the call stack to remember where to backtrack to. Understanding DFS is essential for tackling **Trees**, **Graphs**, **Backtracking**, and many **Dynamic Programming** problems.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* Recursion
* Function Call Stack
* Binary Tree structure (nodes, left/right pointers)
* Basic Stack Concept

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand how DFS explores a tree or graph.
* Differentiate between Preorder, Inorder, and Postorder traversal.
* Trace DFS execution using the function call stack.
* Distinguish DFS from BFS and know when to use each.
* Apply DFS to solve tree and graph-based problems confidently.

---

# 🧠 The Core Idea

DFS explores a structure by going as deep as possible along a branch before backtracking.

## 1️⃣ Base Case

The condition that stops further recursive descent — typically reaching a `null`/`nullptr` node (no children left to explore).

Without a base case, DFS would recurse indefinitely, eventually causing a **Stack Overflow**.

---

## 2️⃣ Recursive Case

The function calls itself on the **child nodes** (left and right, in the case of a binary tree), moving one level deeper with each call.

The *order* in which the current node is processed relative to its children determines the traversal type:

| Traversal | Order |
|-----------|-------|
| **Preorder**  | Node → Left → Right |
| **Inorder**   | Left → Node → Right |
| **Postorder** | Left → Right → Node |

---

# 🔍 How to Recognize This Pattern

DFS is often useful when a problem involves:

* Trees or Graphs
* Exploring all paths or branches
* Backtracking to a previous state
* Connected components
* Path-finding where depth matters more than shortest distance

Common keywords include:

* Tree
* Traverse
* Path
* Connected
* Explore all branches
* Ancestor / Descendant
* Ancestor Sum, Subtree

---

# 📂 Directory Structure

```text
DFS/
├── DFS.cpp
└── README.md
```

---

# 📄 File Overview

## `DFS.cpp`

This file introduces the fundamentals of Depth First Search on a Binary Tree and demonstrates the three classic traversal orders.

### Concepts Covered

* `TreeNode` structure definition
* `dfs_preOrder` — Node → Left → Right
* `dfs_inOrder` — Left → Node → Right
* `dfs_postOrder` — Left → Right → Node
* Recursive descent using the function call stack

The examples are intended to build intuition for traversal order rather than simply demonstrate syntax.

---

# 🧩 How DFS Works

Consider this tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

**Preorder** (Node → Left → Right): `1 2 4 5 3`
**Inorder** (Left → Node → Right): `4 2 5 1 3`
**Postorder** (Left → Right → Node): `4 5 2 3 1`

Execution flow for `dfs_preOrder(1)`:

```text
dfs_preOrder(1)  → print 1
    │
    ▼
dfs_preOrder(2)  → print 2
    │
    ▼
dfs_preOrder(4)  → print 4
    │
    ▼
dfs_preOrder(nullptr) → return (base case)
    │
    ▼
dfs_preOrder(nullptr) → return (base case)
    ▲
    │
back to dfs_preOrder(2) → now visit right child (5)
```

Each call is placed on the **Call Stack** until a `nullptr` (base case) is reached, at which point the stack unwinds and moves on to the next branch.

---

# 📚 The Function Call Stack

Every DFS call is stored in memory until it finishes executing and returns.

```text
Top of Stack
───────────────
dfs_preOrder(4)
dfs_preOrder(2)
dfs_preOrder(1)
───────────────
Bottom of Stack
```

Once a leaf's children (`nullptr`) are reached, the stack unwinds, and DFS backtracks to explore the next unvisited branch.

---

# ⚡ Complexity Analysis

* **Time Complexity:** `O(n)` — every node is visited exactly once.
* **Space Complexity:** `O(h)` — where `h` is the height of the tree, due to the recursive call stack. In the worst case (a skewed tree), this becomes `O(n)`.

Always analyze both the traversal cost and the stack depth, since deep or unbalanced trees can risk stack overflow.

---

# 🌍 Real-World Applications

DFS is widely used in:

* Binary Tree Traversals (Preorder, Inorder, Postorder)
* Graph Traversal & Connected Components
* Cycle Detection in Graphs
* Topological Sorting
* Solving Mazes / Path-finding
* Backtracking problems (subsets, permutations, N-Queens)
* File System Traversal

---

# ⚠️ Common Mistakes

Avoid these common pitfalls:

* Forgetting the base case (`if (!root) return;`), causing infinite recursion.
* Confusing the order of operations between Preorder, Inorder, and Postorder.
* Not marking nodes as visited in graph DFS, causing infinite loops on cycles.
* Assuming DFS always finds the *shortest* path — it doesn't; that's typically BFS's job.
* Ignoring stack overflow risk on very deep/unbalanced trees.

---

# 🎯 Suggested Practice

After understanding DFS, try implementing:

* Preorder / Inorder / Postorder Traversal
* Maximum Depth of Binary Tree
* Path Sum
* Number of Islands (Graph DFS)
* Clone Graph
* Validate Binary Search Tree
* All Paths From Source to Target
* Subsets / Permutations (Backtracking with DFS)

---

# 📝 Key Takeaways

* DFS explores one branch fully before backtracking to the next.
* Preorder, Inorder, and Postorder are all DFS variants — they differ only in when the node is processed.
* DFS relies on the **Call Stack** (explicit or via recursion) to know where to backtrack.
* DFS and BFS are two complementary traversal strategies — DFS goes deep first, BFS goes wide first.

---

# 🔗 Related Patterns

⬅️ Previous: **Recursion**

➡️ Next: **BFS**

🏠 Back to: **Patterns**

🏠 Repository Home
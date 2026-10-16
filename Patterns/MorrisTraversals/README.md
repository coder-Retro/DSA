# 🧵 Morris Traversals Pattern

> **"Borrow the tree's own empty pointers as a temporary stack, and traverse in O(1) space."**

Morris Traversal is a technique for traversing a binary tree in **Preorder** or **Inorder** without recursion and without an explicit stack. Instead of remembering where to return to, it temporarily rewires unused `right` pointers (called **threads**) so that the tree itself tells you how to climb back up.

It is a direct optimization of the recursive DFS traversals: same visiting orders, but the `O(h)` call stack is replaced by `O(1)` extra space.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* Binary Tree structure (nodes, left/right pointers)
* DFS Traversals (Preorder, Inorder, Postorder)
* Recursion and the Function Call Stack
* Inorder Predecessor of a node

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Explain why recursive and stack-based DFS need `O(h)` space.
* Understand how temporary threads replace the stack.
* Find the **inorder predecessor** of a node inside its left subtree.
* Implement Morris Preorder and Morris Inorder traversal.
* Explain why the tree is restored to its original shape after traversal.
* Know the trade-offs and when Morris is (and isn't) a good choice.

---

# 🧠 The Core Idea

In a normal DFS, after finishing a node's left subtree, we need a way to **come back** to that node. Recursion uses the call stack for this; an iterative approach uses an explicit stack.

Morris Traversal gets the same effect for free:

> The **inorder predecessor** of a node `curr` (the rightmost node of its left subtree) always has `right == nullptr`. We temporarily point that empty pointer back to `curr`. When the traversal reaches the predecessor later, following its `right` pointer takes us straight back to `curr`.

## 1️⃣ Find the Predecessor

If `curr` has a left child, walk to the rightmost node of the left subtree:

```cpp
TreeNode* pred = curr->left;
while (pred->right && pred->right != curr) pred = pred->right;
```

The condition `pred->right != curr` stops the loop if a thread already exists from an earlier visit.

## 2️⃣ Create or Remove the Thread

After the loop, `pred->right` tells us which visit this is:

| `pred->right` | Meaning | Action |
|---------------|---------|--------|
| `nullptr` | **First visit** to `curr` | Create thread: `pred->right = curr`, then go left |
| `curr` | **Second visit** (came back via thread) | Remove thread: `pred->right = nullptr`, then go right |

## 3️⃣ No Left Child

If `curr->left` is `nullptr`, there is no left subtree to come back from. Visit `curr` and move to `curr->right` (which may be a thread leading back up).

---

# 🔀 Preorder vs Inorder: Only the Print Moves

The two traversals share the exact same skeleton. The only difference is **when the node is printed**:

| Traversal | Print `curr->val` when... |
|-----------|---------------------------|
| **Preorder** (Node → Left → Right) | No left child, **or** on the **first visit** (thread creation) |
| **Inorder** (Left → Node → Right) | No left child, **or** on the **second visit** (thread removal) |

Why this works:

* **Preorder** wants the node *before* its left subtree, which is exactly the first time we arrive.
* **Inorder** wants the node *after* its left subtree, which is exactly when we return through the thread.

---

# 🔍 How to Recognize This Pattern

Morris Traversal is useful when a problem involves:

* Tree traversal where **extra space is restricted** to `O(1)`
* Inorder-driven logic (BST problems) that must avoid recursion or a stack
* Constraints that explicitly say *"without using recursion or a stack"*
* Very deep trees where recursion risks **stack overflow**

Common keywords include:

* Traverse in `O(1)` space
* Without recursion / without stack
* Inorder / Preorder
* Threaded Binary Tree
* Inorder Predecessor

---

# 📂 Directory Structure

```text
MorrisTraversals/
├── MorrisTraversals.cpp
└── README.md
```

---

# 📄 File Overview

## `MorrisTraversals.cpp`

This file implements Morris Traversal for a binary tree in both Preorder and Inorder form.

### Concepts Covered

* `TreeNode` structure definition
* `morrisPreOrder` — Node → Left → Right
* `morrisInOrder` — Left → Node → Right
* Finding the inorder predecessor
* Creating and removing temporary threads

> The file contains only the traversal functions (no `main`), so it is meant to be included or called from your own driver code.

### Quick Usage

```cpp
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    morrisPreOrder(root);  // 1 2 4 5 3
    cout << "\n";
    morrisInOrder(root);   // 4 2 5 1 3
    cout << "\n";
}
```

---

# 🧩 How Morris Traversal Works

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

### Step-by-step trace of `morrisInOrder(1)`

| Step | `curr` | Predecessor | Action | Output so far |
|------|--------|-------------|--------|---------------|
| 1 | 1 | 5 | `5->right` is null → thread `5→1`, go left | |
| 2 | 2 | 4 | `4->right` is null → thread `4→2`, go left | |
| 3 | 4 | none | No left child → print, follow `right` (thread to 2) | `4` |
| 4 | 2 | 4 | `4->right == 2` → remove thread, print, go right | `4 2` |
| 5 | 5 | none | No left child → print, follow `right` (thread to 1) | `4 2 5` |
| 6 | 1 | 5 | `5->right == 1` → remove thread, print, go right | `4 2 5 1` |
| 7 | 3 | none | No left child → print, `right` is null | `4 2 5 1 3` |
| 8 | null | | Loop ends | |

### The tree while threads exist (after steps 1 and 2)

```text
        1  ◄─────────┐
       / \           │
      2   3          │
     / \             │
    4   5 ───────────┘      (thread 5 → 1)
    │
    └──► thread 4 → 2
```

Each thread is removed on the second visit, so the tree is restored to its original shape by the end.

For **Preorder**, the trace is identical; the print simply moves to steps 1 and 2 (thread creation) instead of 4 and 6 (thread removal), giving `1 2 4 5 3`.

---

# ⚖️ Morris vs Recursive vs Stack

| Approach | Time | Space | Modifies Tree? |
|----------|------|-------|----------------|
| Recursive DFS | `O(n)` | `O(h)` | No |
| Iterative with Stack | `O(n)` | `O(h)` | No |
| **Morris Traversal** | `O(n)` | **`O(1)`** | Temporarily |

---

# ⚡ Complexity Analysis

* **Time Complexity:** `O(n)`. Each node's left subtree is walked at most twice (once to create the thread, once to remove it), and every edge is traversed a small constant number of times, so the total is linear.
* **Space Complexity:** `O(1)`. Only the `curr` and `pred` pointers are used; no stack, no recursion.

Morris is the most **space-efficient** traversal, but not necessarily the fastest in practice: the extra pointer walking means it often runs slightly slower than a stack-based traversal.

---

# 🌍 Real-World Applications

Morris Traversal is useful in:

* Memory-constrained environments (embedded systems)
* Traversing extremely deep or skewed trees without risking stack overflow
* Problems that require inorder traversal of a BST in `O(1)` space
* Recovering a BST where two nodes were swapped, in `O(1)` space
* Understanding **Threaded Binary Trees**, which make this idea permanent

---

# ⚠️ Common Mistakes

Avoid these common pitfalls:

* Writing `while (!curr)` instead of `while (curr)`, so the loop never runs on a non-empty tree.
* Dropping `pred->right != curr` from the predecessor loop, causing an **infinite loop** once a thread exists.
* Forgetting to remove the thread (`pred->right = nullptr`), which leaves the tree corrupted and can loop forever.
* Printing on the wrong visit, which swaps Preorder and Inorder behavior.
* Printing in the `else` branch in Preorder; the thread-removal branch should **not** print.
* Using Morris when the tree must not be modified, even temporarily.

### Safety Notes

Morris Traversal **temporarily modifies the tree**, which makes it unsafe in these situations:

1. If an exception is thrown midway, the tree may be left with leftover threads.
2. If multiple traversals run concurrently on the same tree, they can disturb each other.

---

# 🎯 Suggested Practice

After understanding Morris Traversal, try implementing:

* Binary Tree Inorder Traversal (in `O(1)` space)
* Binary Tree Preorder Traversal (in `O(1)` space)
* Binary Tree Postorder Traversal (Morris with reversed right-chain printing)
* Kth Smallest Element in a BST
* Validate Binary Search Tree
* Recover Binary Search Tree
* Flatten Binary Tree to Linked List

---

# 📝 Key Takeaways

* Morris Traversal replaces the stack with **temporary threads** stored in the tree's own empty `right` pointers.
* The thread connects a node's **inorder predecessor** back to the node itself.
* A null `pred->right` means **first visit** (create thread); `pred->right == curr` means **second visit** (remove thread).
* Preorder prints on the first visit; Inorder prints on the second visit.
* Time is `O(n)` and space is `O(1)`, but the tree is modified while the traversal runs.
* Postorder is also possible, but it is the trickiest variant and needs helper functions for reversing a path.

---

# 🔗 Related Patterns

⬅️ Previous: **DFS**

🏠 Back to: **Patterns**

🏠 Repository Home
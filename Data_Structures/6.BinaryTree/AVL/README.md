# ⚖️ Building an AVL Tree

> **"An AVL Tree is a self-balancing Binary Search Tree in which the heights of the left and right subtrees of every node differ by at most one."**

An AVL Tree is a specialized form of a Binary Search Tree that fixes the BST's biggest weakness: skewed trees. It keeps every BST rule and adds one more:

- Every value in the **left subtree** is smaller than the current node.
- Every value in the **right subtree** is greater than the current node.
- The **heights** of the two subtrees of every node differ by **at most 1**.

After every insertion and deletion, the tree repairs itself using **rotations**, so its height always stays logarithmic.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

- Binary Search Trees
- Recursion
- Pointers and Reference-to-Pointer (`Node*&`)
- Dynamic Memory Allocation
- Tree Traversals

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

- Understand the AVL balance property.
- Compute heights and balance factors.
- Perform left and right rotations.
- Identify and fix all four imbalance cases.
- Insert and delete nodes while keeping the tree balanced.
- Validate an AVL tree and test it with randomized operations.

---

# 📂 Directory Structure

```text
AVL/
├── main.cpp
├── README.md
└── tree.h
```

---

# 🌱 AVL Property

For every node:

```text
Left Subtree  <  Root  <  Right Subtree      (BST property)

|height(Left) − height(Right)|  ≤  1         (AVL property)
```

Example:

```text
          40
         /  \
       20    60
      / \      \
    10  30     80
```

Both properties are preserved after every insertion and deletion.

---

# 📏 Height and Balance Factor

Each node stores its own **height**, so balance can be checked in O(1) instead of recomputing subtree heights.

```cpp
struct Node {
    T val;
    int height;   // leaf = 1, empty subtree = 0
    Node* left;
    Node* right;
};
```

The **balance factor** of a node is:

```text
balance factor = height(left) − height(right)
```

| Balance Factor | Meaning                    |
| :------------: | -------------------------- |
|       +1       | Slightly left-heavy (OK)   |
|        0       | Perfectly balanced (OK)    |
|       −1       | Slightly right-heavy (OK)  |
|      ≥ +2      | Left-heavy, needs fixing   |
|      ≤ −2      | Right-heavy, needs fixing  |

> **Note:** this implementation uses height 1 for a leaf and 0 for an empty subtree. Some texts use 0 for a leaf and −1 for empty. Either works, as long as it is consistent.

---

# 🔁 Rotations

A rotation rearranges a few pointers to shorten one side of the tree and lengthen the other, **without changing the in-order sequence**. That is why the BST property is always preserved.

### Right Rotation (fixes left-heavy)

```text
      y                x
     / \              / \
    x   C    ===>    A   y
   / \                  / \
  A   B                B   C
```

### Left Rotation (fixes right-heavy)

```text
  x                    y
 / \                  / \
A   y     ===>       x   C
   / \              / \
  B   C            A   B
```

Only subtree **B** changes parents. After rewiring, the heights must be updated **lowest node first**, since the new root's height depends on the old root's new height.

Both rotations return the **new root** of the subtree, so the caller can attach it to the parent.

---

# 🧩 The Four Imbalance Cases

When a node's balance factor reaches ±2, look at its heavy child to decide the fix.

| Case        | Node's Balance | Heavy Child's Balance | Fix                                                  |
| ----------- | :------------: | :-------------------: | ---------------------------------------------------- |
| Left-Left   |      > 1       |         ≥ 0           | Right rotation on node                               |
| Left-Right  |      > 1       |         < 0           | Left rotation on child, then right rotation on node  |
| Right-Right |     < −1       |         ≤ 0           | Left rotation on node                                |
| Right-Left  |     < −1       |         > 0           | Right rotation on child, then left rotation on node  |

### Single Rotation (Left-Left)

```text
Insert 3, 2, 1

    3                2
   /                / \
  2      ===>      1   3
 /
1
```

### Double Rotation (Left-Right)

```text
Insert 3, 1, 2

    3             3              2
   /             /              / \
  1     ===>    2     ===>     1   3
   \           /
    2         1

 left-rotate(1)   right-rotate(3)
```

A zigzag cannot be fixed by one rotation, so the zigzag is straightened first, then the single rotation is applied.

> **Tip:** in a double rotation, the child's balance factor has the **opposite sign** of the node's.

---

# 🔨 Search Operation

Searching is identical to a BST. Because the height is guaranteed to be logarithmic, it is always fast.

```text
Searching for 60

      40
        \
         60   ← found
```

Compare with the current node, then move left or right. No rebalancing is needed since searching does not change the tree.

---

# ➕ Insertion

To insert a new value:

1. Walk down from the root exactly like a BST insert.
2. Create the new node when a null link is reached.
3. On the way back up, **update each ancestor's height**.
4. If an ancestor's balance factor becomes ±2, apply the matching rotation.

The implementation is recursive and takes the node link by reference (`Node*&`), so rotations automatically update the parent's pointer.

```cpp
bool pushHelper(Node*& currRoot, const T& val) {
    if(!currRoot) { currRoot = new Node(val); len++; return true; }
    bool pushed = false;
    if(val < currRoot->val)      pushed = pushHelper(currRoot->left, val);
    else if(val > currRoot->val) pushed = pushHelper(currRoot->right, val);
    else                         return false;     // duplicate
    if(pushed) rebalance(currRoot);                // fix on the way back up
    return pushed;
}
```

An insertion needs **at most one** rotation (single or double) to restore balance for the whole tree.

---

# ❌ Deletion

Deletion starts exactly like a BST delete, with three cases:

### Case 1 — Leaf Node

Simply remove it.

---

### Case 2 — One Child

Replace the node with its child.

---

### Case 3 — Two Children

Replace the node's value with its **inorder successor**, then delete the successor from the right subtree.

---

After removal, every ancestor on the path back up is rebalanced.

Unlike insertion, a deletion can trigger rotations at **several** ancestors, because shrinking a subtree can push a higher node out of balance too. This is why `rebalance` runs at every level on the way up.

After a delete, a heavy child can have balance factor **0**, which must be fixed with a **single** rotation. That is why the table uses `≥ 0` and `≤ 0`.

---

# 🔄 Traversals

AVL Trees support the same traversals as BSTs:

- Preorder
- Inorder
- Postorder
- Level Order

**Inorder Traversal** returns the values in sorted order, and the tree's shape never affects that.

---

# ⚡ Complexity Analysis

| Operation | Average  |  Worst   |
| --------- | :------: | :------: |
| Search    | O(log n) | O(log n) |
| Insert    | O(log n) | O(log n) |
| Delete    | O(log n) | O(log n) |
| Traversal |   O(n)   |   O(n)   |

The height of an AVL tree with `n` nodes is at most about **1.44 × log₂(n)**, so even the worst case stays logarithmic.

### BST vs AVL

| Feature                | BST                  | AVL                           |
| ---------------------- | -------------------- | ----------------------------- |
| Worst-case search      | O(n)                 | O(log n)                      |
| Sorted input           | Degrades to a list   | Stays balanced                |
| Extra storage per node | None                 | One `int` for height          |
| Insert / delete cost   | Cheaper              | Slightly more (rotations)     |
| Best for               | Random data, simplicity | Lookup-heavy workloads     |

---

# 🌍 Real-World Applications

AVL Trees are used in:

- Ordered Dictionaries and Sets
- In-Memory Databases and Indexes
- Symbol Tables
- Range Queries
- Scheduling and Event Queues
- Any system where worst-case lookup time matters

Because AVL trees are strictly balanced, they are especially good when searches greatly outnumber updates. Red-Black Trees are a looser alternative that rotates less often, which suits update-heavy workloads.

---

# ⚠️ Common Implementation Mistakes

When implementing an AVL Tree, beginners often:

- **Forget to update heights.** After a rotation, after a recursive insert or delete, or when building a tree from sorted data.
- **Update heights in the wrong order.** In a rotation, the node that ends up lower must be updated first.
- **Copy the wrong sign in the mirror case.** The double-rotation condition flips between the left and right cases.
- **Use a double rotation after a delete when a single one is needed.** A heavy child with balance factor 0 needs a single rotation.
- **Rebalance only once after a delete.** Every ancestor on the path must be checked.
- **Lose subtrees during rotation.** Save the middle subtree before overwriting any pointer.
- **Copy the root pointer instead of the tree.** This causes a double free. Rebuild the tree in the copy constructor and `operator=`.
- **Ignore duplicate values.** Decide how they are handled and keep `size()` consistent.
- **Leak memory** after removing nodes.

Always test:

- Empty and single-node trees
- All four rotation cases (insert `3,2,1`, `3,1,2`, `1,2,3`, `1,3,2`)
- Sorted insertion of `1..1000` (height should be about 10, not 1000)
- Every deletion case (leaf, one child, two children)
- Random inserts and deletes, calling the validator after every operation
- Copy construction and assignment, then modifying one tree and checking the other is unchanged

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

- Floor and Ceiling of a value
- kth Smallest Element
- Range Query (all values between `lo` and `hi`)
- Move Constructor and Move Assignment
- An Iterator over the tree
- Bulk-build from a sorted vector in O(n)
- Compare BST and AVL heights after sorted insertion
- Red-Black Tree

These exercises naturally extend the concepts introduced in this chapter.

---

# 📝 Key Takeaways

- An AVL Tree is a BST that keeps itself balanced.
- Each node stores its height, so the balance factor is computed in O(1).
- Rotations change the tree's shape without changing its in-order sequence.
- Four imbalance cases exist, and each is fixed with one or two rotations.
- Insertion needs at most one rotation; deletion may need several.
- Strict balancing guarantees O(log n) search, insert, and delete.
- A validator and randomized testing are the best defense against silent bugs.

---

# 🔗 Related Implementations

⬅️ **Binary Search Tree** — The ordered tree that AVL builds upon.

⬅️ **Binary Tree** — Provides the hierarchical foundation.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home
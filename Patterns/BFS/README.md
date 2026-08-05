# 🌊 Breadth First Search (BFS) Pattern

> **"Explore all neighbors at the current depth before moving to nodes at the next depth level."**

Breadth First Search is a fundamental traversal technique used whenever a problem needs to explore a structure level by level, rather than branch by branch. It is the go-to pattern for shortest-path problems, level-based tree processing, and graph exploration where distance matters.

BFS is closely tied to the **Queue** data structure—unlike DFS, which uses the call stack (recursion), BFS is almost always implemented iteratively using a queue. Understanding BFS is essential for tackling **Trees**, **Graphs**, and shortest-path problems in general.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* Queues (FIFO)
* Binary Tree structure (nodes, left/right pointers)
* DFS (helps to contrast the two approaches)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand how BFS explores a tree or graph level by level.
* Implement level order traversal using a queue.
* Trace BFS execution and understand the level-size trick.
* Distinguish BFS from DFS and know when to use each.
* Apply BFS to solve shortest-path and level-based problems confidently.

---

# 🧠 The Core Idea

BFS explores a structure by visiting all nodes at the current depth before moving to the next depth level.

## 1️⃣ Base Case

The condition that stops the traversal — typically when the queue becomes empty, meaning every reachable node has been visited.

Without checking for an empty root/queue, BFS could throw an error trying to process a `nullptr`.

---

## 2️⃣ Level Processing

Instead of a recursive case, BFS relies on a **queue** to track which nodes to visit next. The key technique is:

1. Record the current queue size (`s = q.size()`) — this "freezes" the current level.
2. Process exactly `s` nodes from the queue, pushing their children onto the back of the queue.
3. Once all `s` nodes are processed, the queue now contains only the *next* level, and the loop repeats.

This is what lets BFS know exactly when to "drop down" to the next level, without needing to check for leaf nodes directly.

---

# 🔍 How to Recognize This Pattern

BFS is often useful when a problem involves:

* Trees or Graphs
* Shortest path / minimum steps
* Level-by-level processing
* Nearest neighbor exploration
* Finding the minimum number of "hops" between two points

Common keywords include:

* Level
* Shortest path
* Minimum steps / minimum distance
* Nearest
* Layer-by-layer
* Connected in K steps

---

# 📂 Directory Structure

```text
BFS/
├── BFS.cpp
└── README.md
```

---

# 📄 File Overview

## `BFS.cpp`

This file introduces the fundamentals of Breadth First Search on a Binary Tree and demonstrates the classic level order traversal.

### Concepts Covered

* `TreeNode` structure definition
* `bfs_levelOrder` — level-by-level traversal using a queue
* The level-size (`q.size()`) trick to separate levels
* Iterative traversal (no recursion/call stack involved)

The example is intended to build intuition for how BFS processes a structure in layers, in contrast to DFS's branch-first approach.

---

# 🧩 How BFS Works

Consider this tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

**Level Order Traversal:**
```text
Level 0: 1
Level 1: 2 3
Level 2: 4 5
```

Execution flow for `bfs_levelOrder(1)`:

```text
Queue: [1]
─────────────────────
Process level (size=1): pop 1, print 1, push 2, push 3
Queue: [2, 3]
─────────────────────
Process level (size=2): pop 2, print 2, push 4, push 5
                         pop 3, print 3 (no children)
Queue: [4, 5]
─────────────────────
Process level (size=2): pop 4, print 4 (no children)
                         pop 5, print 5 (no children)
Queue: []  → loop ends
```

Unlike DFS, there's no backtracking — nodes are simply processed in the order they entered the queue, level by level.

---

# 📚 The Queue in BFS

Every BFS call relies on a queue to track which nodes are pending, rather than the call stack.

```text
Front of Queue          Back of Queue
─────────────────────────────────────
   4       5     ← current level being pushed
─────────────────────────────────────
```

The queue grows as children are pushed and shrinks as nodes are popped, always maintaining FIFO (First In, First Out) order — which is exactly what preserves level-by-level processing.

---

# ⚡ Complexity Analysis

* **Time Complexity:** `O(n)` — every node is visited and enqueued/dequeued exactly once.
* **Space Complexity:** `O(w)` — where `w` is the maximum width of the tree (the largest number of nodes at any single level), since that's the peak size of the queue. In the worst case (a very wide tree), this can approach `O(n)`.

Always analyze the maximum width of the structure, since that determines peak memory usage — unlike DFS, whose space cost depends on height instead.

---

# 🌍 Real-World Applications

BFS is widely used in:

* Level Order Tree Traversal
* Shortest Path in an Unweighted Graph
* Finding Minimum Steps / Minimum Moves problems
* Web Crawlers (exploring pages layer by layer)
* Social Network "degrees of connection" (e.g. friends of friends)
* Finding the Shortest Path in a Maze/Grid
* Rotting Oranges / Multi-source BFS problems

---

# ⚠️ Common Mistakes

Avoid these common pitfalls:

* Forgetting to check `if(!root) return;` before starting, causing a crash on an empty tree.
* Forgetting to snapshot `q.size()` before the inner loop, which breaks the level-by-level grouping.
* Not marking nodes as visited in graph BFS, causing infinite loops on cycles.
* Assuming BFS is always "better" than DFS — it depends on the problem; BFS shines for shortest path, DFS for exploring all paths/branches.
* Forgetting `#include<queue>` when using `std::queue`.

---

# 🎯 Suggested Practice

After understanding BFS, try implementing:

* Level Order Traversal
* Average of Levels in Binary Tree
* Minimum Depth of Binary Tree
* Rotting Oranges
* Number of Islands (Graph BFS)
* Word Ladder
* Shortest Path in Binary Matrix
* Zigzag Level Order Traversal

---

# 📝 Key Takeaways

* BFS explores all nodes at the current level before moving to the next level.
* BFS is implemented iteratively using a **Queue**, unlike DFS which typically uses recursion/the call stack.
* The `q.size()` snapshot trick is the key to separating one level from the next.
* DFS and BFS are two complementary traversal strategies — DFS goes deep first, BFS goes wide first.

---

# 🔗 Related Patterns

⬅️ Previous: **DFS**

➡️ Next: **BinaryTree / Graphs**

🏠 Back to: **Patterns**

🏠 Repository Home
<img src="https://capsule-render.vercel.app/api?type=venom&height=200&color=gradient&text=Graph&fontSize=60&fontColor=FFFFFF&animation=fadeIn&fontAlignY=35&desc=Breadth%20First%20%7C%20Depth%20First&descSize=35&descColor=FFFFFF&descAlignY=65" width="100%"/>

# 🕸️ Graph Algorithms

> **"Graph algorithms answer one question: how do we move through a network of connected things?"**

A graph is a collection of nodes connected by edges, and it can model almost anything: roads between cities, friends in a social network, links between web pages, or the cells of a maze. A graph algorithm is a systematic way of walking through that structure so that every node is visited, a target is found, or a path is discovered.

This chapter introduces the two fundamental graph traversal techniques:

* **Breadth First Search (BFS)** – Explores the graph level by level, using a queue.
* **Depth First Search (DFS)** – Explores one path as deep as possible before backing up, using recursion.

Almost every other graph algorithm (shortest paths, cycle detection, topological sorting, connected components) is built on top of one of these two.

---

# 📖 Prerequisites

Before studying this chapter, you should understand:

* Graph Basics (nodes, edges, neighbors, cycles)
* Queues
* Recursion and the Call Stack
* Hash Tables (`unordered_map`, `unordered_set`)
* 2D Vectors (matrices)
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand how BFS and DFS traverse a graph.
* Explain why a `visited` marker is needed when a graph has cycles.
* Check whether a path exists between two nodes using BFS.
* Find every path through a maze using DFS with backtracking.
* Choose between BFS and DFS for a given problem.
* Analyze the time and space complexity of both algorithms.
* Avoid common traversal mistakes.

---

# 📂 Directory Structure

```text
Graph/
├── BreadthFirstSearch.cpp
├── DepthFirstSearch.cpp
└── README.md
```

---

# 📄 Files in this Chapter

## 🔹 `BreadthFirstSearch.cpp`

Implements `pathExists`, which uses BFS to check whether a destination node can be reached from a source node in an undirected graph.

### Concepts Covered

* Level by level traversal
* Iterative queue
* Visited marking
* Adjacency list (`unordered_map<int, vector<int>>`)
* Path existence in connected and disconnected graphs

---

## 🔹 `DepthFirstSearch.cpp`

Implements `allPaths`, which uses DFS with backtracking to find every path from the top-left cell to the bottom-right cell of a maze. This is the classic **"Rat in a Maze"** problem.

### Concepts Covered

* Recursive traversal and the call stack
* Backtracking (mark a cell, explore, then unmark it)
* Grid graph (`vector<vector<int>>`)
* Boundary and wall checks
* Building a path with `push_back` and `pop_back`

---

# 🧠 Choosing the Right Traversal

```text
        Need to explore a graph?
                  │
                  ▼
   Need the shortest path (unweighted)?
          │                  │
         Yes                 No
          │                  │
          ▼                  ▼
         BFS        Need every possible path?
                          │            │
                         Yes           No
                          │            │
                          ▼            ▼
                 DFS + Backtracking   BFS or DFS
```

If all you need is to know whether two nodes are connected, **both** algorithms work. Pick BFS when distance matters and DFS when you need to follow a path to its end or enumerate every path.

---

# 🧱 How Graphs Are Represented Here

This chapter uses two common representations:

| Representation | Type | Used In | Meaning |
| -------------- | ---- | ------- | ------- |
| Adjacency List | `unordered_map<int, vector<int>>` | BFS | Each node maps to the list of its neighbors |
| Grid (Matrix)  | `vector<vector<int>>` | DFS | Each cell is a node connected to its up, down, left and right cells |

In the maze, `0` is an open cell and `1` is a wall.

---

# 🌊 Breadth First Search

BFS explores the graph in **layers**. It visits the source, then everything one edge away, then everything two edges away, and so on. A **queue** keeps the nodes waiting to be explored in the order they were discovered.

### How It Works

1. Push the source into the queue and mark it **visited**.
2. Take a node off the front of the queue. If it is the destination, return `true`.
3. For every neighbor not yet visited, mark it visited and push it into the queue.
4. If the queue empties, every reachable node was checked and the destination was not among them. Return `false`.

```cpp
queue<int> q;
q.push(source);
unordered_set<int> visited;
visited.insert(source);
while(!q.empty()) {
    int node=q.front();
    q.pop();
    if(node==destination) return true;
    for(int neighbor:graph[node]) {
        if(!visited.contains(neighbor)) {
            q.push(neighbor);
            visited.insert(neighbor);
        }
    }
}
return false;
```

### Example

The demo builds this undirected graph from the edges `{0,1} {1,2} {1,3} {2,4} {5,6}`:

```text
0 ─── 1 ─── 2 ─── 4          5 ─── 6
      │
      3
```

Searching from `0` to `4`:

```text
queue: [0]        visit 0 → push 1
queue: [1]        visit 1 → push 2, 3
queue: [2, 3]     visit 2 → push 4
queue: [3, 4]     visit 3 → nothing new
queue: [4]        visit 4 → destination reached, True
```

Searching from `0` to `5` visits `0 1 2 3 4`, the queue empties, and the result is `False`, because `5` and `6` live in a separate component.

### The `visited` Marker

Without it, a cycle such as `1 → 2 → 3 → 1` would make the search loop forever. Nodes are marked visited when they are **added** to the queue, not when they leave it, so the same node can never be queued twice.

### Advantages

* Finds the shortest path in an unweighted graph.
* Visits nodes in order of their distance from the source.
* Never gets stuck going down one very long path.

### Disadvantages

* The queue can grow very large on wide graphs.
* Not suited to enumerating every path.

---

# 🕳️ Depth First Search

DFS follows one path **as deep as it can go**. When it reaches a dead end, it returns to the previous node and tries the next path. Instead of an explicit queue, it uses **recursion**, so the call stack remembers where to return to.

### How It Works

For every cell in the maze:

1. If the cell is out of bounds or a wall, return.
2. If the cell is the bottom-right corner, save the current path and return.
3. Mark the cell visited.
4. Try each direction in turn (Up, Down, Left, Right), adding the move to the path before the recursive call and removing it afterward.
5. **Unmark** the cell before returning, so it can be used again by a different path.

Step 5 is **backtracking**, and it is what makes finding *every* path possible.

```cpp
maze[i][j]=1; // Marking Cell As Visited
p.push_back('U'); dfs(maze,r,c,i-1,j,p,ps); p.pop_back();
p.push_back('D'); dfs(maze,r,c,i+1,j,p,ps); p.pop_back();
p.push_back('L'); dfs(maze,r,c,i,j-1,p,ps); p.pop_back();
p.push_back('R'); dfs(maze,r,c,i,j+1,p,ps); p.pop_back();
maze[i][j]=0; // Marking Cell As Unvisited
```

### Example

The demo maze (`0` = open, `1` = wall) has two valid paths from `(0,0)` to `(4,4)`:

```text
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
0 1 1 1 0
0 0 0 0 0
```

```text
Path 1: DDDDRRRR            Path 2: DDRRUURRDDDD

* # . . .                   * # * * *
* # . # .                   * # * # *
* . . # .                   * * * # *
* # # # .                   . # # # *
* * * * *                   . . . . *
```

The directions are tried in the order Up, Down, Left, Right, which is why `DDDDRRRR` is printed first.

### Advantages

* Very short and natural to write with recursion.
* Uses little memory when the graph is wide.
* Can enumerate every path, with backtracking.

### Disadvantages

* Does **not** guarantee the shortest path.
* Very deep graphs can overflow the call stack.
* Finding all paths is exponential.

---

# 📊 Complexity Analysis

`V` = number of vertices, `E` = number of edges, `r` and `c` = rows and columns of the maze.

| Algorithm | Time | Space |
| --------- | :--: | :---: |
| BFS (`pathExists`) | O(V+E) | O(V) |
| DFS, plain traversal | O(V+E) | O(V) |
| DFS, all paths (`allPaths`) | O(4^(r\*c)) | O(r\*c) |

* **BFS** processes every vertex once and examines every edge. Its extra space is the queue and the `visited` set. The graph itself is the input, so it is not counted.
* **DFS, plain traversal** has the same time cost. Its extra space is the call stack plus the `visited` marker.
* **DFS, all paths** is exponential because cells are unmarked on the way back, so the same cell is explored again along many different paths. Space is only the recursion depth and the current path, both at most `r*c`, with the output excluded.

The cost of finding all paths grows quickly. On an empty `n x n` grid, the number of recursive calls is 157 for 3x3, 4,349 for 4x4, 326,397 for 5x5, and over 68 million for 6x6.

---

# 📊 BFS vs DFS

| Feature | BFS | DFS |
| ------- | --- | --- |
| Data Structure | Queue | Recursion (call stack) |
| Traversal Order | Level by level | Branch by branch |
| Shortest Path (unweighted) | ✅ | ❌ |
| Finds All Paths | ❌ | ✅ (with backtracking) |
| Space Pressure | Wide graphs | Deep graphs |
| Visited Marking | Permanent | Temporary when finding all paths |
| Ease of Implementation | ⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ |

---

# 🌍 Real-World Applications

### BFS

* Shortest route in an unweighted network
* Social network "degrees of separation"
* Web crawling
* Level order traversal of trees
* Minimum moves in puzzles and games
* Broadcasting in computer networks

### DFS

* Maze solving and path enumeration
* Cycle detection
* Topological sorting
* Finding connected components
* Backtracking puzzles (Sudoku, N-Queens)
* Exploring file systems

---

# ⚠️ Common Mistakes

### BFS

* Forgetting the `visited` set, which loops forever on any graph with a cycle.
* Marking nodes visited only when they leave the queue, so the same node is queued many times.
* Forgetting to mark the **source** visited. Note that `unordered_set<int> visited(source);` does **not** insert the source. It is the bucket-count constructor. Use `visited.insert(source);` or `visited={source};`.
* Using `graph[node]` on a missing node, which silently adds it to the map.

---

### DFS

* Forgetting to unmark the cell on the way back, which makes the search miss valid paths.
* Forgetting `pop_back()` after a recursive call, which leaves a corrupted path.
* Checking `maze[i][j]` before checking the bounds, which reads outside the grid.
* Assuming the first path DFS finds is the shortest.
* Running on very deep inputs without considering the call stack limit.

Always test edge cases such as:

* Empty graph or empty maze
* Source equal to destination
* Disconnected graph
* Graph containing a cycle
* Start or destination blocked by a wall
* A 1x1 maze
* A fully blocked maze

---

# 🎯 Suggested Practice

After completing this chapter, try solving:

### BFS

* Find if Path Exists in Graph
* Nearest Exit from Entrance in Maze
* Rotting Oranges
* Shortest Path in Binary Matrix
* Word Ladder

### DFS

* Number of Islands
* Flood Fill
* Max Area of Island
* All Paths From Source to Target
* Clone Graph
* Word Search

### Both

* Is Graph Bipartite?
* Course Schedule

These problems apply the traversals from this chapter and are common in technical interviews.

---

# 📝 Key Takeaways

* BFS explores level by level with a queue and finds the shortest path in an unweighted graph.
* DFS explores branch by branch with recursion and is the natural fit for enumerating paths.
* A `visited` marker is what stops a traversal from looping forever on cycles.
* Backtracking means undoing a choice after exploring it, so another path can use the same node.
* BFS and plain DFS both run in O(V+E) time, but finding all paths with DFS is exponential.
* BFS and DFS are the foundation for most advanced graph algorithms.

---

# 🔗 Continue Learning

⬅️ Previous: **Calculative Algorithms**

➡️ Next: **Data Structures**

🏠 Back to: **Algorithms**

🏠 Repository Home
<img src="https://capsule-render.vercel.app/api?type=venom&height=200&color=gradient&text=Graph&fontSize=60&fontColor=FFFFFF&animation=fadeIn&fontAlignY=35&desc=Breadth%20First%20%7C%20Depth%20First%20%7C%20Dijkstra&descSize=30&descColor=FFFFFF&descAlignY=65" width="100%"/>

# 🕸️ Graph Algorithms

> **"Graph algorithms answer one question: how do we move through a network of connected things?"**

A graph is a collection of nodes connected by edges, and it can model almost anything: roads between cities, friends in a social network, links between web pages, or the cells of a maze. A graph algorithm is a systematic way of walking through that structure so that every node is visited, a target is found, or a path is discovered.

This chapter introduces the two fundamental graph traversal techniques, plus one shortest path algorithm built on top of them:

* **Breadth First Search (BFS)** – Explores the graph level by level, using a queue.
* **Depth First Search (DFS)** – Explores one path as deep as possible before backing up, using recursion.
* **Dijkstra's Algorithm** – Finds the cheapest path from one source to every other node in a weighted graph, using a min heap.

Almost every other graph algorithm (cycle detection, topological sorting, connected components) is built on top of BFS or DFS. Dijkstra's algorithm is a good example: it is BFS with the queue replaced by a min heap, so that edges with different weights can be handled.

---

# 📖 Prerequisites

Before studying this chapter, you should understand:

* Graph Basics (nodes, edges, neighbors, cycles)
* Queues
* Recursion and the Call Stack
* Hash Tables (`unordered_map`, `unordered_set`)
* 2D Vectors (matrices)
* Priority Queues / Min Heaps (`priority_queue` with `greater<>`)
* Weighted Graphs (edges that carry a cost)
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand how BFS and DFS traverse a graph.
* Explain why a `visited` marker is needed when a graph has cycles.
* Check whether a path exists between two nodes using BFS.
* Find every path through a maze using DFS with backtracking.
* Find the shortest path from one node to all others in a weighted graph using Dijkstra's Algorithm.
* Explain relaxation and why Dijkstra's greedy choice is safe only for non-negative weights.
* Choose between BFS, DFS and Dijkstra for a given problem.
* Analyze the time and space complexity of each algorithm.
* Avoid common traversal mistakes.

---

# 📂 Directory Structure

```text
Graph/
├── BreadthFirstSearch.cpp
├── DepthFirstSearch.cpp
├── Dijkstra.cpp
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

## 🔹 `Dijkstra.cpp`

Implements `shortestPath`, which uses Dijkstra's Algorithm to find the shortest distance from a source node to every other node in an undirected, weighted graph. Nodes that cannot be reached are reported as `INF`.

### Concepts Covered

* Greedy choice (always finalize the closest unfinalized node)
* Min heap (`priority_queue` with `greater<>`)
* Relaxation of edges
* Lazy deletion of stale heap entries
* Weighted adjacency list (`unordered_map<int, vector<pair<int, int>>>`)
* Unreachable nodes in a disconnected graph

---

# 🧠 Choosing the Right Traversal

```text
          Need to explore a graph?
                    │
                    ▼
          Need the shortest path?
            │                │
           Yes               No
            │                │
            ▼                ▼
     Are edges weighted?   Need every possible path?
        │          │          │             │
       Yes         No        Yes            No
        │          │          │             │
        ▼          ▼          ▼             ▼
    Dijkstra      BFS    DFS + Backtracking  BFS or DFS
```

If all you need is to know whether two nodes are connected, **both** algorithms work. Pick BFS when distance is measured in number of edges, Dijkstra when edges have different costs, and DFS when you need to follow a path to its end or enumerate every path.

Dijkstra requires **non-negative** edge weights. If a graph can contain negative weights, use Bellman-Ford instead. If every edge has the same weight, Dijkstra does the work of BFS with extra overhead, so use BFS.

---

# 🧱 How Graphs Are Represented Here

This chapter uses three common representations:

| Representation | Type | Used In | Meaning |
| -------------- | ---- | ------- | ------- |
| Adjacency List | `unordered_map<int, vector<int>>` | BFS | Each node maps to the list of its neighbors |
| Grid (Matrix)  | `vector<vector<int>>` | DFS | Each cell is a node connected to its up, down, left and right cells |
| Weighted Adjacency List | `unordered_map<int, vector<pair<int, int>>>` | Dijkstra | Each node maps to a list of `(neighbor, weight)` pairs |

In the maze, `0` is an open cell and `1` is a wall.

In the weighted adjacency list, an undirected edge `{u, v, w}` is stored twice: `v` with weight `w` under `u`, and `u` with weight `w` under `v`. The number of vertices `n` is passed to `shortestPath` separately, because `graph.size()` only counts nodes that have at least one edge.

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

# 🛣️ Dijkstra's Algorithm

Dijkstra's Algorithm answers: *"what is the cheapest way to get from the source to every other node?"* BFS counts edges, so it only finds the cheapest path when every edge costs the same. Dijkstra handles edges with different costs, such as distance, time or price.

Think of dropping a stone in water at the source. The ripple reaches nearer nodes first and farther nodes later. Dijkstra works the same way: it always advances to the closest node that has not been finalized yet. A **min heap** of `(distance, node)` pairs keeps that order.

### How It Works

1. Create a `dists` array holding infinity for every node, except `0` for the source.
2. Push `(0, source)` into the min heap.
3. Pop the pair with the smallest distance. If its distance is larger than `dists[u]`, it is **stale**, so skip it.
4. For every neighbor `v` of `u` with edge weight `w`, check whether `dists[u] + w < dists[v]`. This check is called **relaxation**.
5. If the new route is cheaper, update `dists[v]` and push `(dists[v], v)` into the heap.
6. Repeat until the heap is empty. Any node still holding infinity is unreachable from the source.

```cpp
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
pq.push({0,source});
dists[source]=0;
while(!pq.empty()) {
    auto [d,u]=pq.top();
    pq.pop();
    if(d>dists[u]) continue; // Stale Entry
    for(auto [v,w]:graph[u]) {
        if(dists[v]>dists[u]+w) {
            dists[v]=dists[u]+w;
            pq.push({dists[v],v});
        }
    }
}
return dists;
```

### Example

The demo builds this undirected, weighted graph from the edges `{0,1,4} {1,2,3} {1,3,1} {2,4,2} {5,6,5}`:

```text
0 ──4── 1 ──3── 2 ──2── 4          5 ──5── 6
        │
        1
        │
        3
```

Running from source `0` (`∞` means not reached yet):

```text
heap: (0,0)
pop (0,0)   relax 1 → 4              dists: 0 4 ∞ ∞ ∞ ∞ ∞
pop (4,1)   relax 2 → 7, 3 → 5       dists: 0 4 7 5 ∞ ∞ ∞
pop (5,3)   nothing is shorter       dists: 0 4 7 5 ∞ ∞ ∞
pop (7,2)   relax 4 → 9              dists: 0 4 7 5 9 ∞ ∞
pop (9,4)   nothing is shorter       dists: 0 4 7 5 9 ∞ ∞
heap empty  done
```

```text
0->0 = 0
0->1 = 4
0->2 = 7
0->3 = 5
0->4 = 9
0->5 = INF
0->6 = INF
```

Nodes are finalized in the order `0, 1, 3, 2, 4`, which is increasing distance (`0, 4, 5, 7, 9`). Nodes `5` and `6` are never pushed, because no path from `0` reaches them. They keep `INT_MAX`, which the demo prints as `INF`.

### Why Stale Entries Exist

A node can be pushed more than once when a cheaper route to it is found later. A `priority_queue` cannot delete from the middle, so the old entry stays behind. Take the edges `{0,1,10} {0,2,1} {2,1,2}` from source `0`:

```text
pop (0,0)    push (10,1) and (1,2)
pop (1,2)    1 + 2 = 3 < 10, so dists[1] = 3, push (3,1)
pop (3,1)    process node 1 normally
pop (10,1)   10 > dists[1] = 3, stale, skipped
```

Without the `continue`, the result is still correct, but node 1 is processed a second time for nothing.

### Why the Greedy Choice Is Safe

When `u` is the closest unfinalized node, any other route to `u` must pass through some node that is at least as far away. Adding more non-negative edges cannot make that route shorter, so `dists[u]` can never improve. With a **negative** edge, a longer-looking route could later become cheaper, and this argument breaks. That is why Dijkstra needs non-negative weights.

### Advantages

* Finds the shortest path from one source to **every** node in a single run.
* Works on weighted graphs, which BFS cannot handle.
* Efficient with a min heap, even on large sparse graphs.

### Disadvantages

* Does **not** work with negative edge weights (use Bellman-Ford).
* Slower than BFS when all edges have the same cost.
* Needs the vertex count and a valid source up front in this implementation.

---

# 📊 Complexity Analysis

`V` = number of vertices, `E` = number of edges, `r` and `c` = rows and columns of the maze.

| Algorithm | Time | Space |
| --------- | :--: | :---: |
| BFS (`pathExists`) | O(V+E) | O(V) |
| DFS, plain traversal | O(V+E) | O(V) |
| DFS, all paths (`allPaths`) | O(4^(r\*c)) | O(r\*c) |
| Dijkstra (`shortestPath`) | O((V+E) log V) | O(V+E) |

* **BFS** processes every vertex once and examines every edge. Its extra space is the queue and the `visited` set. The graph itself is the input, so it is not counted.
* **DFS, plain traversal** has the same time cost. Its extra space is the call stack plus the `visited` marker.
* **DFS, all paths** is exponential because cells are unmarked on the way back, so the same cell is explored again along many different paths. Space is only the recursion depth and the current path, both at most `r*c`, with the output excluded.

* **Dijkstra** scans each vertex's neighbors once, which is O(V+E) in total. Every successful relaxation pushes into the heap, so there are at most E pushes, and each push or pop costs O(log V). That gives O((V+E) log V). Its extra space is the `dists` array, O(V), plus the heap, which can hold up to one entry per successful relaxation, so O(E) in the worst case because stale entries are removed lazily.

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

# 📊 BFS vs Dijkstra

| Feature | BFS | Dijkstra |
| ------- | --- | -------- |
| Data Structure | Queue | Min Heap (`priority_queue`) |
| Edge Weights | All equal (unweighted) | Different, but non-negative |
| Shortest Path | ✅ (by number of edges) | ✅ (by total cost) |
| Negative Weights | Not applicable | ❌ (use Bellman-Ford) |
| Time | O(V+E) | O((V+E) log V) |
| Marks Node Final | When first reached | When popped with its smallest distance |

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

### Dijkstra

* GPS and map route planning (shortest or fastest route)
* Network routing protocols such as OSPF
* Minimum delay or minimum cost in a network
* Cheapest travel routes (flights, trains)
* Pathfinding in games (A\* is Dijkstra plus a heuristic)
* "Minimum cost path" problems where the cost is not simply a sum, such as minimizing the maximum height or effort along a path

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

---

### Dijkstra

* Using it on a graph with negative edge weights, which gives wrong answers.
* Using the default `priority_queue`, which is a **max** heap. Add `greater<pair<int,int>>` to get a min heap.
* Pushing `(node, distance)` instead of `(distance, node)`. The heap orders by the first element, so the distance must come first.
* Forgetting the stale check `if(d>dists[u]) continue;`. The answer stays correct, but nodes are processed more than once.
* Using `graph.size()` as the vertex count. It only counts nodes that have at least one edge, so isolated nodes and sparse IDs break it.
* Not validating `source` before `dists[source]=0`. An out of range source writes outside the vector. This is undefined behavior and may not crash, so a quick run proves nothing.
* Overflow with `INT_MAX`. `dists[u]+w` is safe here because only finite nodes are popped, but use `long long` if weights can be large.
* Printing `INT_MAX` for unreachable nodes instead of a clear marker such as `INF`.

Always test edge cases such as:

* Empty graph or empty maze
* Source equal to destination
* Disconnected graph
* Graph containing a cycle
* Start or destination blocked by a wall
* A 1x1 maze
* A fully blocked maze
* A source outside the valid node range (Dijkstra)
* Unreachable nodes, which must stay `INF` (Dijkstra)
* Zero-weight edges, parallel edges and self-loops (Dijkstra)

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

### Dijkstra

* Network Delay Time
* Cheapest Flights Within K Stops
* Path With Minimum Effort
* Path With Maximum Probability
* Swim in Rising Water
* Trapping Rain Water II

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
* Dijkstra finds the shortest path from one source to every node in a weighted graph by always finalizing the closest unfinalized node, using a min heap.
* Relaxation is the core step: update a neighbor's distance whenever going through the current node is cheaper.
* Dijkstra is correct only for non-negative edge weights, and runs in O((V+E) log V).
* BFS and DFS are the foundation for most advanced graph algorithms, and Dijkstra is BFS with a min heap in place of the queue.

---

# 🔗 Continue Learning

⬅️ Previous: **Calculative Algorithms**

➡️ Next: **Data Structures**

🏠 Back to: **Algorithms**

🏠 Repository Home
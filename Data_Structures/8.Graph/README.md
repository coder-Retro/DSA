# 🕸️ Building a Graph

> **"A Graph is a collection of nodes (vertices) connected by edges. It models relationships: roads between cities, friendships between people, links between web pages."**

A Graph is the most general of the basic data structures. Lists, trees, and even hash tables can be seen as special cases of it. This implementation is an **undirected, unweighted graph** stored as an **adjacency list**, so every node keeps a set of the nodes it is connected to.

- An **edge** between `a` and `b` means `a` is connected to `b` **and** `b` is connected to `a`.
- Each node stores its neighbors in a **hash set**, so duplicate edges are impossible.
- Nodes can exist **without any edges** (isolated nodes).
- **Self-loops** (`a — a`) are allowed.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

- Hash Tables (`unordered_map`, `unordered_set`)
- Queues
- References and `const`-correctness
- Exceptions (`throw`, `try` / `catch`)
- Structured Bindings (`auto& [key, value]`)
- Basic Tree Traversals (BFS especially)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

- Understand what a graph is and how it differs from a tree.
- Represent a graph as an adjacency list.
- Add and remove nodes and edges while keeping the graph consistent.
- Explain why undirected edges are stored twice.
- Handle self-loops without corrupting the structure.
- Check whether two nodes are connected using Breadth-First Search (BFS).
- Count nodes, edges, and degrees correctly.
- Test a graph class against edge cases.

---

# 📂 Directory Structure

```text
Graph/
├── main.cpp
├── README.md
└── graph.h
```

`Graph.h` holds the class, and `main.cpp` is a demo that exercises every method.

---

# 🌱 Graph Terminology

```text
Nodes (vertices):  1, 2, 3, 4, 5, 6
Edges:             1-2, 2-3, 3-4, 4-1, 5-6

   1 ─── 2          5 ─── 6
   │     │
   4 ─── 3
```

| Term              | Meaning                                                     |
| ----------------- | ----------------------------------------------------------- |
| Node / Vertex     | A point in the graph                                        |
| Edge              | A connection between two nodes                              |
| Neighbor          | A node directly connected to another node                   |
| Degree            | The number of neighbors a node has                          |
| Path              | A sequence of nodes where each consecutive pair is an edge  |
| Cycle             | A path that starts and ends at the same node                |
| Self-loop         | An edge from a node to itself                               |
| Connected         | Two nodes are connected if a path exists between them       |
| Component         | A group of nodes that are all connected to each other       |
| Isolated node     | A node with no edges                                        |

In the example above there are **two components**: `{1, 2, 3, 4}` and `{5, 6}`. There is no path from `1` to `6`.

### Graph vs Tree

| Feature          | Tree                         | Graph                          |
| ---------------- | ---------------------------- | ------------------------------ |
| Cycles           | Never                        | Allowed                        |
| Root             | Exactly one                  | None                           |
| Connectivity     | Always connected             | May have several components    |
| Edges (n nodes)  | Exactly n − 1                | Any number                     |

---

# 🧱 Representation

This graph is an **adjacency list**: a map from each node to the set of its neighbors.

```cpp
std::unordered_map<int, std::unordered_set<int>> graph;
```

The graph from the terminology section is stored as:

```text
1 → { 2, 4 }
2 → { 1, 3 }
3 → { 2, 4 }
4 → { 1, 3 }
5 → { 6 }
6 → { 5 }
```

Every edge appears **twice**, once in each endpoint's set. That is what makes the graph undirected, and it is why `addEdge` and `removeEdge` always update both sides.

### Why a Set Instead of a Vector?

| Feature                  | `vector<int>`          | `unordered_set<int>`       |
| ------------------------ | ---------------------- | -------------------------- |
| Duplicate edges          | Must be checked by hand | Impossible                 |
| `hasEdge`                | O(degree)              | O(1) average               |
| `removeEdge`             | O(degree)              | O(1) average               |
| Neighbor order           | Insertion order        | Arbitrary (hash order)     |
| Memory                   | Smaller                | Larger                     |

The trade-off is that neighbor order is **not guaranteed**. If you need deterministic output, copy the neighbors and sort them (the demo in `main.cpp` does this).

### Adjacency List vs Adjacency Matrix

| Feature               | Adjacency List          | Adjacency Matrix        |
| --------------------- | ----------------------- | ----------------------- |
| Memory                | O(V + E)                | O(V²)                   |
| `hasEdge`             | O(1) average (with set) | O(1)                    |
| List all neighbors    | O(degree)               | O(V)                    |
| Best for              | Sparse graphs           | Dense graphs            |

---

# 🧩 Class Overview

```cpp
class Graph {
private:
    std::unordered_map<int, std::unordered_set<int>> graph;
    void requireNode(int node) const;   // throws if the node is missing

public:
    Graph() = default;
    Graph(const std::vector<std::vector<int>>& edges);

    // Modify
    void addNode(int node);
    void removeNode(int node);
    void addEdge(int node1, int node2);
    void removeEdge(int node1, int node2);
    void isolate(int node);
    void clear();

    // Query
    bool hasNode(int node) const;
    bool hasEdge(int node1, int node2) const;
    bool hasPath(int src, int dst) const;
    size_t degree(int node) const;
    const std::unordered_set<int>& neighbors(int node) const;
    size_t nodeCount() const;
    size_t edgeCount() const;
    bool empty() const;
    const std::unordered_map<int, std::unordered_set<int>>& getGraph() const;
};
```

The class declares **no** destructor, copy constructor, or move operations. Its only member is a standard container that manages its own memory, so the compiler-generated versions are correct (the **Rule of Zero**).

---

# ➕ Adding Nodes and Edges

### addNode

```cpp
void addNode(int node) { graph[node]; }
```

`operator[]` creates an empty set if the key does not exist, and does nothing if it does. Adding the same node twice is harmless.

### addEdge

```cpp
void addEdge(int node1, int node2) {
    graph[node1].insert(node2);
    graph[node2].insert(node1);
}
```

- **Missing nodes are created automatically**, so you can build a graph from edges alone.
- **Duplicates are ignored**, because a set refuses to store the same value twice. Calling `addEdge(1, 2)` and then `addEdge(2, 1)` still produces a single edge.
- **A self-loop** `addEdge(5, 5)` runs `insert(5)` twice on the same set, so it is stored **once**.

### Edge-List Constructor

```cpp
Graph g({{1, 2}, {2, 3}, {3, 4}});
```

Each inner vector is one edge `{node1, node2}`.

---

# ❌ Removing Edges and Nodes

### removeEdge

```cpp
void removeEdge(int node1, int node2) {
    requireNode(node1);
    requireNode(node2);
    graph[node1].erase(node2);
    graph[node2].erase(node1);
}
```

- Throws `std::runtime_error` if either node does not exist.
- If both nodes exist but the edge does not, it does **nothing** (no error).
- The nodes themselves remain, even if they end up with no edges.

### isolate

Removes **every edge** of a node but keeps the node.

```cpp
void isolate(int node) {
    requireNode(node);
    auto& connections = graph[node];
    for (int connection : connections)
        if (connection != node) graph[connection].erase(node);
    connections.clear();
}
```

For each neighbor, the node is erased from the neighbor's set. Then the node's own set is cleared.

> **Why the `connection != node` check?** If the node has a self-loop, it is in its own set. Erasing it from `graph[node]` while iterating over that same set is **undefined behavior**. The guard skips the self-loop, and `clear()` removes it safely afterwards.

### removeNode

```cpp
void removeNode(int node) { isolate(node); graph.erase(node); }
```

First `isolate` removes every reference to the node from other nodes' sets, then the node's own entry is erased. Skipping the first step would leave **dangling references**: neighbors that point to a node that no longer exists.

```text
removeNode(2)

Before:             After isolate(2):      After erase:
1 → {2, 3}          1 → {3}                1 → {3}
2 → {1, 3}          2 → {}                 3 → {1}
3 → {1, 2}          3 → {1}
```

---

# 🔍 Queries

### hasNode and hasEdge

```cpp
bool hasNode(int node) const { return graph.contains(node); }

bool hasEdge(int node1, int node2) const {
    auto it = graph.find(node1);
    return it != graph.end() && it->second.contains(node2);
}
```

`hasEdge` never throws. If either node is missing, the answer is simply `false`. It uses `find` instead of `operator[]` so that **asking a question never changes the graph**.

### degree and neighbors

```cpp
size_t degree(int node) const;
const std::unordered_set<int>& neighbors(int node) const;
```

Both throw if the node does not exist. `neighbors` returns a **const reference** to the internal set, so no copy is made.

> **Warning:** the reference is invalidated if the graph is modified afterwards. Use it immediately, or copy it if you need to keep it.

> **Self-loop note:** a self-loop is counted **once** in `degree`. Textbooks usually count it twice. This implementation keeps it simple, but document the choice if you change it.

### nodeCount, edgeCount, empty, clear

```cpp
size_t edgeCount() const {
    size_t sum = 0, self = 0;
    for (const auto& [node, connections] : graph) {
        sum += connections.size();
        if (connections.contains(node)) self++;
    }
    return (sum + self) / 2;
}
```

Each normal edge is stored twice, so it adds **2** to the sum. A self-loop is stored once, so it adds only **1**. Counting the self-loops separately and adding them back before dividing makes every edge contribute exactly 2.

| Graph                  | sum | self | (sum + self) / 2 |
| ---------------------- | :-: | :--: | :--------------: |
| edge 1-2               |  2  |  0   |        1         |
| self-loop 1-1          |  1  |  1   |        1         |
| edge 1-2 + loop 1-1    |  3  |  1   |        2         |

---

# 🧭 Path Search (BFS)

`hasPath(src, dst)` answers: **is there any route from `src` to `dst`?**

It uses **Breadth-First Search**: explore the source, then all its neighbors, then all of *their* neighbors, and so on, level by level.

```cpp
bool hasPath(int src, int dst) const {
    requireNode(src);
    requireNode(dst);
    std::queue<int> q;
    q.push(src);
    std::unordered_set<int> visited{src};
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == dst) return true;
        for (int neighbor : graph.at(node))
            if (visited.insert(neighbor).second) q.push(neighbor);
    }
    return false;
}
```

### How It Works

1. Put the source in a queue and mark it **visited**.
2. Take a node off the queue. If it is the destination, return `true`.
3. For every neighbor not yet visited, mark it visited and add it to the queue.
4. If the queue empties, every reachable node was checked and the destination was not among them. Return `false`.

```text
hasPath(1, 3) on:   1 ─── 2 ─── 3        queue: [1]
                                          visit 1 → queue: [2]
                                          visit 2 → queue: [3]
                                          visit 3 → found!
```

### The `visited` Set

Without it, a cycle (`1 → 2 → 3 → 1`) would make the search loop forever. `visited.insert(neighbor).second` is `true` only when the value was **newly inserted**, so one hash lookup both checks and marks the node.

### Details

- `src == dst` returns `true` immediately, since a node always reaches itself.
- Nodes in different components return `false`.
- `graph.at(node)` is used instead of `graph[node]` because `operator[]` is not allowed in a `const` method.
- Throws if either node is missing.

---

# 📸 getGraph

```cpp
std::unordered_map<int, std::unordered_set<int>> getGraph() const { return graph; }
```

Returns a **full copy** of the adjacency list. Changing the copy never affects the original, which makes it safe for printing or inspection, at the cost of O(V + E) per call. For read-only access without copying, prefer `neighbors()` and `hasEdge()`.

---

# ⚠️ Error Handling

| Method                            | Missing node behavior            |
| --------------------------------- | -------------------------------- |
| `addNode`, `addEdge`              | Creates the node(s)              |
| `hasNode`, `hasEdge`              | Returns `false`                  |
| `removeEdge`                      | Throws `std::runtime_error`      |
| `isolate`, `removeNode`           | Throws `std::runtime_error`      |
| `degree`, `neighbors`             | Throws `std::runtime_error`      |
| `hasPath`                         | Throws `std::runtime_error`      |

The rule: **questions that can honestly be answered "no" return `false`; operations and lookups that need a node to exist throw.** Adding is forgiving because creating a missing node is always a sensible interpretation.

```cpp
try {
    g.removeEdge(1, 999);
} catch (const std::runtime_error& e) {
    std::cout << e.what();   // "Node 999 does not exist!"
}
```

---

# ⚡ Complexity Analysis

`V` = number of nodes, `E` = number of edges, `d` = degree of the node involved.

| Operation       | Average   | Notes                              |
| --------------- | :-------: | ---------------------------------- |
| `addNode`       | O(1)      | Hash insert                        |
| `addEdge`       | O(1)      | Two hash inserts                   |
| `removeEdge`    | O(1)      | Two hash erases                    |
| `hasNode`       | O(1)      | Hash lookup                        |
| `hasEdge`       | O(1)      | Two hash lookups                   |
| `degree`        | O(1)      | Size of a set                      |
| `neighbors`     | O(1)      | Returns a reference                |
| `isolate`       | O(d)      | One erase per neighbor             |
| `removeNode`    | O(d)      | `isolate` plus one erase           |
| `nodeCount`     | O(1)      |                                    |
| `edgeCount`     | O(V)      | Visits every node                  |
| `hasPath`       | O(V + E)  | Each node and edge visited once    |
| `getGraph`      | O(V + E)  | Full copy                          |
| `clear`         | O(V + E)  | Frees every set                    |

Hash operations are O(1) on average. In the worst case (many hash collisions) they degrade, but this is rare in practice.

---

# 🌍 Real-World Applications

Graphs are used in:

- Social Networks (friends, followers)
- Maps and Navigation (roads between places)
- Computer Networks (routers and links)
- Web Crawling (pages and hyperlinks)
- Recommendation Systems
- Dependency Resolution (build systems, package managers)
- Game Maps and Puzzle Solving
- Scheduling and Resource Allocation

Whenever the question is "how are these things connected?", a graph is usually the answer.

---

# ⚠️ Common Implementation Mistakes

When implementing a Graph, beginners often:

- **Update only one side of an edge.** In an undirected graph, both endpoints must change.
- **Erase from a set while iterating over it.** This happens in `isolate` when a node has a self-loop.
- **Leave dangling references.** Erasing a node without removing it from its neighbors' sets.
- **Use `operator[]` in a `const` method or in a query.** It does not compile on a const map, and it silently *creates* missing nodes in non-const code. Use `find`, `at`, or `contains` instead.
- **Divide the degree sum by 2 and forget self-loops.** A self-loop is stored once, so it is undercounted.
- **Return a reference to a temporary.** Building a vector inside `neighbors()` and returning it by reference leaves a dangling reference.
- **Keep a `neighbors()` reference across modifications.** Adding or removing edges can invalidate it.
- **Forget the `visited` set in BFS.** Any graph with a cycle will loop forever.
- **Mark nodes visited only when they leave the queue.** The same node can be queued many times. Mark it when it is **added**.
- **Allow duplicate edges by accident.** With `vector` adjacency, `addEdge` must check `hasEdge` first.
- **Depend on neighbor order.** Hash sets have no guaranteed order.
- **Forget `-std=c++20`.** `contains` requires C++20.

Always test:

- Empty graph and single-node graph
- Duplicate `addEdge` calls
- Self-loops: add, `degree`, `edgeCount`, `isolate`, `removeNode`
- `removeEdge` on an edge that does not exist
- `hasPath` with `src == dst`, in the same component, and across components
- `hasPath` on a graph that contains a cycle
- A long chain (for example 10,000 nodes) to check BFS does not overflow or slow down
- Every method that should throw on a missing node
- Copy construction, then modifying one graph and checking the other is unchanged
- Compiling with `-fsanitize=address,undefined` to catch invalidated iterators and memory errors

---

# ▶️ Building and Running

```text
g++ -std=c++20 -Wall -Wextra -Wshadow main.cpp -o main
./main
```

`main.cpp` builds a graph, calls every method, and prints labeled results, including the exceptions thrown for missing nodes.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

- Depth-First Search (iterative, to avoid stack overflow on deep graphs)
- BFS that returns the visit order
- `shortestPath(src, dst)` returning the actual path (BFS with a parent map)
- `connectedComponents()` and `isConnected()`
- Cycle detection (`hasCycle`)
- Bipartite check (two-coloring with BFS)
- An `initializer_list` constructor, so `Graph g{{1,2},{2,3}};` works
- `operator==` (defaulted in C++20) and `operator<<` for printing
- Make the edge-list constructor `explicit`
- A **weighted** graph and Dijkstra's algorithm
- A **directed** graph and topological sort
- A template version supporting `std::string` or custom node types
- Adjacency matrix version, then compare it with this one

These exercises naturally extend the concepts introduced in this chapter.

---

# 📝 Key Takeaways

- A graph is a set of nodes connected by edges, and unlike a tree it may contain cycles and several components.
- An adjacency list stores each node's neighbors, using O(V + E) memory.
- In an undirected graph every edge is stored twice, so every edge operation updates both endpoints.
- A hash set per node makes `hasEdge`, `addEdge`, and `removeEdge` O(1) on average and prevents duplicate edges.
- Self-loops are stored once, so they need special care in `isolate` and `edgeCount`.
- Remove a node's edges **before** erasing the node, or neighbors will keep dangling references.
- BFS with a `visited` set finds out whether two nodes are connected in O(V + E).
- Queries should never modify the graph, so prefer `find` and `at` over `operator[]`.
- Because the class owns nothing but a standard container, the Rule of Zero gives correct copy and move behavior for free.

---

# 🔗 Related Implementations

⬅️ **Binary Tree** — A tree is a connected graph with no cycles.

⬅️ **AVL Tree** — Another structure built from linked nodes, but with a strict hierarchy.

➡️ **Weighted / Directed Graph** — The natural next step after this chapter.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home
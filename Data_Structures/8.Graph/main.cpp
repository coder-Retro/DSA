#include <iostream>
#include <algorithm>
#include "graph.h"

// Prints "label: true/false"
void show(const std::string& label, bool value) {
    std::cout << "  " << label << ": " << (value ? "true" : "false") << "\n";
}

// Prints the whole graph, sorted so the output is stable
void printGraph(const Graph& g) {
    auto adjacency = g.getGraph();
    std::vector<int> nodes;
    for (const auto& [node, _] : adjacency) nodes.push_back(node);
    std::sort(nodes.begin(), nodes.end());

    for (int node : nodes) {
        std::vector<int> nbrs(adjacency[node].begin(), adjacency[node].end());
        std::sort(nbrs.begin(), nbrs.end());
        std::cout << "  " << node << " -> [";
        for (size_t i = 0; i < nbrs.size(); ++i)
            std::cout << (i ? ", " : "") << nbrs[i];
        std::cout << "]\n";
    }
}

void stats(const Graph& g) {
    std::cout << "  nodes=" << g.nodeCount() << ", edges=" << g.edgeCount() << "\n";
}

int main() {
    Graph g;

    std::cout << "=== 1. New graph ===\n";
    show("empty()", g.empty());
    stats(g);

    std::cout << "\n=== 2. addNode / addEdge ===\n";
    g.addNode(1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);   // closes a cycle 1-2-3-4-1
    g.addEdge(5, 6);   // separate component (nodes created automatically)
    printGraph(g);
    stats(g);

    std::cout << "\n=== 3. Duplicate addEdge is ignored ===\n";
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    stats(g);

    std::cout << "\n=== 4. hasNode / hasEdge ===\n";
    show("hasNode(3)", g.hasNode(3));
    show("hasNode(99)", g.hasNode(99));
    show("hasEdge(1, 2)", g.hasEdge(1, 2));
    show("hasEdge(2, 1)  (undirected)", g.hasEdge(2, 1));
    show("hasEdge(1, 3)", g.hasEdge(1, 3));
    show("hasEdge(1, 99) (missing node, no throw)", g.hasEdge(1, 99));

    std::cout << "\n=== 5. degree / neighbors ===\n";
    std::cout << "  degree(1) = " << g.degree(1) << "\n";
    std::cout << "  neighbors(1) = {";
    {
        std::vector<int> n(g.neighbors(1).begin(), g.neighbors(1).end());
        std::sort(n.begin(), n.end());
        for (size_t i = 0; i < n.size(); ++i) std::cout << (i ? ", " : "") << n[i];
    }
    std::cout << "}\n";

    std::cout << "\n=== 6. hasPath ===\n";
    show("hasPath(1, 3)  (same component)", g.hasPath(1, 3));
    show("hasPath(1, 6)  (different components)", g.hasPath(1, 6));
    show("hasPath(5, 6)", g.hasPath(5, 6));
    show("hasPath(2, 2)  (src == dst)", g.hasPath(2, 2));

    std::cout << "\n=== 7. removeEdge ===\n";
    g.removeEdge(4, 1);
    std::cout << "  removed edge 4-1\n";
    show("hasEdge(1, 4)", g.hasEdge(1, 4));
    show("hasPath(1, 4) (still reachable via 2, 3)", g.hasPath(1, 4));
    stats(g);

    std::cout << "\n=== 8. isolate ===\n";
    g.isolate(2);
    std::cout << "  isolated node 2 (node stays, edges go)\n";
    printGraph(g);
    show("hasNode(2)", g.hasNode(2));
    std::cout << "  degree(2) = " << g.degree(2) << "\n";
    show("hasPath(1, 3) (route through 2 is gone)", g.hasPath(1, 3));

    std::cout << "\n=== 9. removeNode ===\n";
    g.removeNode(2);
    std::cout << "  removed node 2\n";
    show("hasNode(2)", g.hasNode(2));
    stats(g);

    std::cout << "\n=== 10. Self-loops ===\n";
    g.addEdge(7, 7);
    show("hasEdge(7, 7)", g.hasEdge(7, 7));
    std::cout << "  degree(7) = " << g.degree(7) << "  (loop counted once)\n";
    stats(g);
    g.removeNode(7);
    std::cout << "  removeNode(7) worked without crashing\n";

    std::cout << "\n=== 11. Edge-list constructor ===\n";
    Graph h({{10, 20}, {20, 30}, {30, 40}});
    printGraph(h);
    stats(h);

    std::cout << "\n=== 12. Copy is independent ===\n";
    Graph copy = h;
    copy.removeNode(20);
    std::cout << "  after removing 20 from the copy:\n";
    std::cout << "  original has node 20? " << (h.hasNode(20) ? "yes" : "no") << "\n";
    std::cout << "  copy has node 20?     " << (copy.hasNode(20) ? "yes" : "no") << "\n";

    std::cout << "\n=== 13. getGraph snapshot ===\n";
    auto snapshot = h.getGraph();
    snapshot[10].insert(999);   // changes only the copy
    show("original hasEdge(10, 999)", h.hasEdge(10, 999));

    std::cout << "\n=== 14. Exceptions on missing nodes ===\n";
    try { g.degree(999); }
    catch (const std::runtime_error& e) { std::cout << "  degree(999)      -> " << e.what() << "\n"; }
    try { g.neighbors(999); }
    catch (const std::runtime_error& e) { std::cout << "  neighbors(999)   -> " << e.what() << "\n"; }
    try { g.removeEdge(1, 999); }
    catch (const std::runtime_error& e) { std::cout << "  removeEdge(1,999)-> " << e.what() << "\n"; }
    try { g.isolate(999); }
    catch (const std::runtime_error& e) { std::cout << "  isolate(999)     -> " << e.what() << "\n"; }
    try { g.removeNode(999); }
    catch (const std::runtime_error& e) { std::cout << "  removeNode(999)  -> " << e.what() << "\n"; }
    try { g.hasPath(1, 999); }
    catch (const std::runtime_error& e) { std::cout << "  hasPath(1,999)   -> " << e.what() << "\n"; }

    std::cout << "\n=== 15. clear ===\n";
    g.clear();
    show("empty()", g.empty());
    stats(g);

    return 0;
}
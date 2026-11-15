#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
Use Case:
Breadth First Search (BFS) is an extremely useful graph
algorithm used to traverse a complex hierarchical data
structure like a "Tree" or "Graph" level by level. It is
used where the search needs to expand from a node in all
directions, walking one edge at a time in each direction.
Think of it like standing at a junction with 2 to n paths
in front of you. BFS tells you to walk one edge on path 1,
one edge on path 2, one edge on path 3 ... one edge on
path n. Now that you have walked one edge on each of the
n paths, walk a second edge on path 1, then a second edge
on path 2, and so on until the whole tree or graph has
been traversed. It is often used for traversal and
searching. It works by using an iterative queue to save
the immediate neighbors of the current node before moving
ahead of it. However, graphs can also have cycles, so a
node can be reached from multiple paths, which may cause
the same node to be visited more than once. BFS avoids
this by marking a node as visited the first time it is
reached. When it is reached again, it is ignored and not
pushed into the queue, so no duplicate visits are
processed. For this purpose, a secondary data structure
is used to mark nodes as visited, usually a vector or an
unordered_set. The time complexity of BFS is O(V+E),
where V and E are the number of vertices (nodes) and
edges respectively, since every vertex is processed once
and every edge is examined. The space complexity is O(V),
due to the queue and the visited marker. BFS is mainly
used to verify if a path exists between two nodes in a
graph. On an unweighted graph, it also finds the shortest
path between these two nodes.
Examples:
Level Order Traversal of a Binary Tree is an initial
(easy to understand) example of BFS.
*/

/*
Approach: BFS / Queue
TC: O(V+E), V = number of vertices, E = number of edges
SC: O(V)
*/

class BFS {
public:
    bool pathExists(unordered_map<int,vector<int>>& graph,int source,int destination) {
        queue<int> q;
        q.push(source); // Pushing Source
        unordered_set<int> visited;
        visited.insert(source); // Marking Source As Visited
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            if(node==destination) return true; // Destination Reached
            for(int neighbor:graph[node]) { // Checking Neighbors
                if(!visited.contains(neighbor)) { // Unvisited Neighbor
                    q.push(neighbor); // Pushing Unvisited Neighbor
                    visited.insert(neighbor); // Marking Neighbor As visited
                }
            }
        }
        return false; // Destination Can't Be Reached
    }
};

int main() {
    BFS obj;
    vector<vector<int>> edges={{0,1},{1,2},{1,3},{2,4},{5,6}};
    unordered_map<int,vector<int>> graph;
    // Make Unweighted & Undirected Graph
    for(auto& edge:edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    cout<<(obj.pathExists(graph,0,4)?"True":"False")<<'\n'; // 0->1->2->4
    cout<<(obj.pathExists(graph,0,5)?"True":"False")<<'\n'; // No path from 0 to 5
    return 0;
}
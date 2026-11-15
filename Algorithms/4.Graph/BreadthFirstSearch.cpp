#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
Use Case:
Breadth First Search (BFS) algorithm is an extremely useful
graphing algorithm used to traverse a complex heirarichal
data structure like "Tree" or "Graph" level by level. It
is used where the search space needs to expand from a node
in all directions walking one edge at a time each direction.
Think of it like standing at a junction where you have 2 to n
paths infront of you. BFS tells you to walk one edge on path 1, 
1 edge on path 2, 1 edge on path 3 ... 1 edge on path n. Now
that you have walked one edge on each of n paths. Now walk
a second edge on path 1, then a second edge on path 2 and so
on until you have traversed the whole tree or graph. It is
often used for traversal and searching. It works by using an
iterative queue to save the immediate neighbors of the current
node before moving ahead of it. However graphs can also have
cycles and hence a node can be reached from multiple paths
which may cause multiple visits to the same node. This is a
problem but BFS has a special mechanism in it that allows it
to mark a node as visited and the next time it is reached again,
it is ignored and not pushed into the iterative queue, hence no
duplicate visits are processed at all. For this purpose, a
secondary data structure is used to mark nodes as visited,
usually a vector or unordered_set. The time complexity of
BFS is O(V) where V is the number of vertices or nodes. Space
complexity is  O(V+E) where V and E are number of vertices/node
and edges respectively. This space is due to the iterative queue
and the visit marker (vector or set). BFS is mainly used to verify
is a path exists between two nodes in a graph, it also gives the
shortest path between these two nodes.
Examples:
LevelOrder Traversal of Binary Tree is an initial(Easy to Understand)
example of BFS.
*/

/*
Approach: BFS / Queue
TC: O(V)
SC: O(V+E)
*/

class BFS {
public:
    bool pathExists(unordered_map<int,vector<int>>& graph,int source,int destination) {
        queue<int> q; q.push(source); // Pushing Source
        unordered_set<int> visited(source); // Marking Source As Visited
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            if(node==destination) return true; // Destination Reached
            for(int neighbor:graph[node]) { // Checking Neighbors
                if(!visited.contains(neighbor)) { // Unvisited Neighbor
                    q.push(neighbor); // Pushing Unvisited Neighbor
                    visited.insert(neighbor); // Markgin Neighbor as visited
                }
            }
        }
        return false; // Destination Cant Be Reached
    }
};

int main() {
    BFS obj;
    vector<vector<int>> edges={{0,1},{1,2},{1,3},{2,4},{5,6}};
    unordered_map<int,vector<int>> graph;
    //  Make Unweighted & Undirected Graph
    for(auto& edge:edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    cout<<(obj.pathExists(graph,0,4)?"True":"False")<<'\n'; // 0->1->2->4
    cout<<(obj.pathExists(graph,0,5)?"True":"False")<<'\n'; // No path from 0 to 5
    return 0;
}
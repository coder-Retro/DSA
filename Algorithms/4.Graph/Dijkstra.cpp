#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

/*
Use Case:
Dijkstra's Algorithm is a greedy graph algorithm used to
find the shortest path from a single source node to every
other node in a weighted graph, as long as every edge
weight is non-negative. BFS treats every edge as having the
same cost, so it only finds shortest paths on unweighted
graphs. Dijkstra handles edges with different costs, such
as distance, time or price. Think of dropping a stone in
water at the source node. The ripple reaches nearer nodes
first and farther nodes later. Dijkstra works the same way,
always advancing to the closest node that has not been
finalized yet. It works by keeping a distance array, which
starts at infinity for every node and 0 for the source, and
a min heap of (distance, node) pairs. The node with the
smallest distance is popped from the heap, and for each of
its neighbors we check whether going through this node is
cheaper than the best route known so far. This check is
called relaxation. If it is cheaper, the neighbor's
distance is updated and the neighbor is pushed into the
heap with its new distance. This greedy choice is safe
because weights are non-negative: the closest unfinalized
node can never be reached more cheaply through a farther
node, since adding more edges can't reduce the total cost.
A node may be pushed multiple times as better routes are
found, and a priority queue cannot delete from the middle,
so older entries stay behind. When one of them is popped,
its distance is greater than the best known distance, so it
is stale and is skipped. Nodes that are never reached keep
the value infinity, which tells us they are unreachable
from the source. The time complexity of Dijkstra is
O((V+E) log V), where V and E are the number of vertices
and edges respectively, since every edge can cause a push
into the heap and every push or pop costs O(log V). The
space complexity is O(V+E) for the graph, and O(V) for the
distance array and the heap. Dijkstra does not work with
negative edge weights, so Bellman-Ford should be used
there. Dijkstra is also the base of many "minimum cost
path" problems where the cost of a path is not simply the
sum of its edges, such as minimizing the maximum edge on a
path.
Examples:
Network Delay Time, Cheapest Flights Within K Stops and
Path With Minimum Effort are classic examples. Trapping
Rain Water II uses a Dijkstra-style min heap where the
path cost is the maximum height along the path. In the
real world, GPS route planning and network routing
protocols like OSPF are built on the same idea.
*/

/*
Approach: Greedy / Min Heap
TC: O((V+E) log V), V = number of vertices, E = number of edges
SC: O(V+E) for the graph, O(V) for dists and heap
*/

class Dijkstra {
public:
    vector<int> shortestPath(int source,unordered_map<int,vector<pair<int,int>>>& graph,int n) {
        vector<int> dists(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,source});
        dists[source]=0;
        while(!pq.empty()) {
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dists[u]) continue;
            for(auto [v,w]:graph[u]) {
                if(dists[v]>dists[u]+w) {
                    dists[v]=dists[u]+w;
                    pq.push({dists[v],v});
                }
            }
        }
        return dists;
    }
};

int main() {
    Dijkstra obj;
    int n=7;
    // {u, v, weight}
    vector<vector<int>> edges={{0,1,4},{1,2,3},{1,3,1},{2,4,2},{5,6,5}};
    // Making Undirected and Weighted Graph
    unordered_map<int,vector<pair<int,int>>> graph;
    for (auto& edge:edges) {
        graph[edge[0]].push_back({edge[1],edge[2]});
        graph[edge[1]].push_back({edge[0],edge[2]});
    }
    // Calling Dijsktra's Shortest Path
    int source=0;
    vector<int> dist=obj.shortestPath(source,graph,n);
    for (int i=0;i<(int)dist.size();i++)
        cout<<source<<"->"<<i<<" = "<<(dist[i]==INT_MAX?"INF":to_string(dist[i]))<<"\n";
    return 0;
}
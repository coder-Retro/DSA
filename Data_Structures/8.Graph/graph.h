#include<stdexcept>
#include<cstddef>
#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<utility>

class Graph {
private:
    std::unordered_map<int,std::unordered_set<int>> graph;
    void requireNode(int node) const {
        if (!graph.contains(node))
            throw std::runtime_error("Node "+std::to_string(node)+" does not exist!");
    }
public:
    Graph()=default;
    Graph(const std::vector<std::vector<int>>& edges) {
        for(auto& edge:edges) addEdge(edge[0],edge[1]);
    }
    void addNode(int node) { graph[node]; }
    void removeNode(int node) { isolate(node); graph.erase(node); }
    void addEdge(int node1,int node2) {
        graph[node1].insert(node2);
        graph[node2].insert(node1);
    }
    void removeEdge(int node1,int node2) {
        requireNode(node1);
        requireNode(node2);
        graph[node1].erase(node2);
        graph[node2].erase(node1);
    }
    void isolate(int node) {
        requireNode(node);
        auto& connections=graph[node];
        for(int connection:connections)
            if(connection!=node) graph[connection].erase(node);
        connections.clear();
    }
    bool hasNode(int node) const { return graph.contains(node); }
    bool hasEdge(int node1,int node2) const {
        auto it=graph.find(node1);
        return it!=graph.end() && it->second.contains(node2);
    }
    bool hasPath(int src,int dst) const {
        requireNode(src);
        requireNode(dst);
        std::queue<int> q;
        q.push(src);
        std::unordered_set<int> visited{src};
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            if(node==dst) return true;
            for(int neighbor:graph.at(node)) {
                if(visited.insert(neighbor).second) q.push(neighbor);
            }
        }
        return false;
    }
    size_t degree(int node) const { requireNode(node); return graph.at(node).size(); }
    const std::unordered_set<int>& neighbors(int node) const {
        requireNode(node);
        return graph.at(node);
    }
    size_t nodeCount() const { return graph.size(); }
    size_t edgeCount() const {
        size_t sum=0,self=0;
        for(const auto& [node,connections]:graph) {
            sum+=connections.size();
            if(connections.contains(node)) self++;
        }
        return (sum+self)/2;
    }
    bool empty() const { return graph.empty(); }
    void clear() { graph.clear(); }
    const std::unordered_map<int,std::unordered_set<int>>& getGraph() const { return graph; }
};
#include<vector>
#include<unordered_map>
using namespace std;

// Helper Definition & Functions
struct Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val=0;
        neighbors=vector<Node*>();
    }
    Node(int _val) {
        val=_val;
        neightbors=vector<Node*>();
    }
    Node(int _val,vector<Node*> _neighbors) {
        val=_val;
        neighbors=_neighbors;
    }
};

/*
Approach: Hashing / Recursion / DFS / Memoization
TC: O(v+e), v and e are number of nodes and their edges
SC: O(v), v = number of nodes
*/

class Solution {
    Node* dfs(Node* node,unordered_map<Node*,Node*>& clones) {
        if(clones.contains(node)) return clones[node];
        Node* clone=new Node(node->val);
        clones[node]=clone;
        for(Node* neighbor:node->neighbors)
            clone->neighbors.push_back(dfs(neighbor,clones));
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> clones;
        return dfs(node,clones);
    }
};
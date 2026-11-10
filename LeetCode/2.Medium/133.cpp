#include<vector>
#include<queue>
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
        neighbors=vector<Node*>();
    }
    Node(int _val,vector<Node*> _neighbors) {
        val=_val;
        neighbors=_neighbors;
    }
};

/*
Approach: Hashing / BFS / Queue
TC: O(v+e), v and e are number of nodes and their edges
SC: O(v), v = number of nodes
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> clones;
        clones[node]=new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            Node* curr=q.front();
            q.pop();
            for(Node* neighbor:curr->neighbors) {
                if(!clones.contains(neighbor)) {
                    clones[neighbor]=new Node(neighbor->val);
                    q.push(neighbor);
                }
                clones[curr]->neighbors.push_back(clones[neighbor]);
            }
        }
        return clones[node];
    }
};
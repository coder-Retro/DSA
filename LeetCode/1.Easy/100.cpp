#include<queue>
using namespace std;

// Helper Definition & Functions
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Approach: BFS / Queue
TC: O(n)
SC: O(w), w = width of the tree
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        queue<TreeNode*> q1; q1.push(p);
        queue<TreeNode*> q2; q2.push(q);
        while(!q1.empty()) {
            TreeNode* n1=q1.front(); q1.pop();
            TreeNode* n2=q2.front(); q2.pop();
            if(n1->val!=n2->val) return false;
            if((!n1->left) ^ (!n2->left))   return false;
            if((!n1->right) ^ (!n2->right)) return false;
            if(n1->left)  { q1.push(n1->left);  q2.push(n2->left);  }
            if(n1->right) { q1.push(n1->right); q2.push(n2->right); }
        }
        return q1.empty() && q2.empty();
    }
};
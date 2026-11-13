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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node=q.front(); q.pop();
            if(!node->left && !node->right && !(targetSum-node->val))
                return true;
            if(node->left) {
                node->left->val+=node->val;
                q.push(node->left);
            }
            if(node->right) {
                node->right->val+=node->val;
                q.push(node->right);
            }
        }
        return false;
    }
};
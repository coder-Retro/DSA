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
Approach: Recursion / DFS
TC: O(n)
SC: O(h), h = height of tree
*/

class Solution {
    bool dfs(TreeNode* root) {
        if(!root) return false;
        if(root->left)
            if(root->val==root->left->val+root->right->val)
                return true;
        return dfs(root->left) || dfs(root->right);
    }
public:
    bool checkTree(TreeNode* root) {
        return dfs(root);
    }
};
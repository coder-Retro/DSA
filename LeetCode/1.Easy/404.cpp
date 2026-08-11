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
SC: O(n)
*/

class Solution {
    int dfs(TreeNode* root,bool isLeft) {
        if(!root) return 0;
        if(!root->left && !root->right && isLeft)
            return root->val;
        return dfs(root->left,true)+dfs(root->right,false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root,false);
    }
};
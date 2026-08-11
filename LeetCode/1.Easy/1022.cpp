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
Approach: Recursion / DFS / Bit Manupulation 
TC: O(n)
SC: O(h), h = height of tree
*/

class Solution {
    int dfs(TreeNode* root,unsigned int sum) {
        if(!root) return 0;
        sum=(sum<<1)|root->val;
        if(!root->left && !root->right) return sum;
        return dfs(root->left,sum)+dfs(root->right,sum);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
};
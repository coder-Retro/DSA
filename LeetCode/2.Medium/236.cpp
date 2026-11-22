// Helper Definition & Functions
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Approach: Recursion / DFS
TC: O(n)
SC: O(h), h is the height of tree
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode* on_L=lowestCommonAncestor(root->left,p,q);
        TreeNode* on_R=lowestCommonAncestor(root->right,p,q);
        if(on_L && on_R) return root;
        return on_L?on_L:on_R;
    }
};
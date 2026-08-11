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
TC: O(m+n) m and n are number of nodes in both trees
SC: O(h1+h2), h1 and h2 are heights of both trees
*/

class Solution {
    void leafOrder(TreeNode* root,vector<int>& v) {
        if(!root) return;
        if(!root->left && !root->right) v.push_back(root->val);
        leafOrder(root->left,v);
        leafOrder(root->right,v);
    }
public:
    bool leafSimilar(TreeNode* root1,TreeNode* root2) {
        vector<int> v1,v2;
        leafOrder(root1,v1);
        leafOrder(root2,v2);
        return (v1==v2);
    }
};
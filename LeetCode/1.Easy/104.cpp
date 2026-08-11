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
    void depthCount(TreeNode* root,int depth,int& maxD) {
        if(!root) return;
        depth++;
        maxD=max(maxD,depth);
        depthCount(root->left,depth,maxD);
        depthCount(root->right,depth,maxD);
    }
public:
    int maxDepth(TreeNode* root) {
        int maxD=0;
        depthCount(root,0,maxD);
        return maxD;
    }
};
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
Approach: Recursion
TC: O(n)
SC: O(h), h = height of tree
*/

class Solution {
    void inOrder(TreeNode* root,int& ans,int& k) {
        if(!root) return;
        inOrder(root->left,ans,k);
        if(!(--k)) { ans=root->val; return; }
        inOrder(root->right,ans,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inOrder(root,ans,k);
        return ans;
    }
};
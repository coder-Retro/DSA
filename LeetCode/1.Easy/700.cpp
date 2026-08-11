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
Approach: Binary Search
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root)
            if(val<root->val)      root=root->left;
            else if(val>root->val) root=root->right;
            else                   break;
        return root;
    }
};
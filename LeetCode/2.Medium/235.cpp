// Helper Definition & Functions
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Approach: Binary Search / Split Detection
TC: O(h), h is the height of tree
SC: O(1)
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if(p->val<root->val && q->val<root->val)
                root=root->left;
            else if(p->val>root->val && q->val>root->val)
                root=root->right;
            else return root;
        }
        return nullptr;
    }
};
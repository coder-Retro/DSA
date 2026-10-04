// Helper definition & Functions
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
Approach: Recursion / BFS
TC: O(n)
SC: O(n)
*/

class Solution {
    void dfs(TreeNode*& root,int val) {
        if(!root) return;
        if(val<root->val) { dfs(root->left,val);  return; }
        if(val>root->val) { dfs(root->right,val); return; }
        if(!root->left || !root->right) {
            TreeNode* target=root;
            if(!root->left) root=root->right;
            else            root=root->left;
            delete target;
        } else {
            TreeNode* succ=root->right;
            while(succ->left) succ=succ->left;
            root->val=succ->val;
            dfs(root->right,succ->val);
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        dfs(root,key);
        return root;
    }
};
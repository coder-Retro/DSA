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
    void dfs(TreeNode* root,vector<TreeNode*>& pre) {
        if(!root) return;
        pre.push_back(root);
        dfs(root->left,pre);
        dfs(root->right,pre);
    }
    void transform(TreeNode* root,vector<TreeNode*>& pre) {
        for(int i=0;i<pre.size();i++) {
            pre[i]->left=nullptr;
            if(i==pre.size()-1) {
                pre[i]->right=nullptr;
                break;
            }
            pre[i]->right=pre[i+1];
        }
    }
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> preOrder;
        dfs(root,preOrder);
        transform(root,preOrder);
    }
};
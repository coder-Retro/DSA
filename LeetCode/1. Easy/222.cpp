struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    void countNodes(TreeNode* root,int& n)
    {
        if(root==nullptr) return;
        n++;
        countNodes(root->left,n);
        countNodes(root->right,n);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int totalNodes=0;
        countNodes(root,totalNodes);
        return totalNodes;
    }
};
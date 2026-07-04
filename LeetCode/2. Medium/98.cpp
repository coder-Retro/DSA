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
    void inOrder(TreeNode* root,vector<int>& order)
    {
        if(!root) return;
        inOrder(root->left,order);
        order.push_back(root->val);
        inOrder(root->right,order);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> order;
        inOrder(root,order);
        for(int i=0;i<order.size()-1;i++)
            if(order[i]>=order[i+1])
                return false;
        return true;
    }
};
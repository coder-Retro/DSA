struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    int sumLeaf(TreeNode* root,int sum) {
        if(!root) return 0;
        sum=sum*10+root->val;
        if(!root->left && !root->right) return sum;
        return sumLeaf(root->left,sum)+sumLeaf(root->right,sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumLeaf(root,0);
    }
}
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int toDecimal(string n) {
        int decimal=0;
        int power=1;
        for(int i=n.length()-1;i>=0;i--) {
            if(n[i]=='1')
                decimal+=power;
            power*=2;
        }
        return decimal;
    }
    void traverse(TreeNode* root,string sum,int& total) {
        if(!root) return;
        
        if(root->val==1) sum+="1";
        else sum+="0";

        if(!root->left && !root->right) {
            total+=toDecimal(sum);
            return;
        }
        traverse(root->left,sum,total);
        traverse(root->right,sum,total);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int total=0;
        traverse(root,"",total);
        return total;
    }
};
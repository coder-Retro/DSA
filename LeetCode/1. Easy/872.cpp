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
    void leafOrder(TreeNode* root,vector<int>& v) {
        if(!root) return;
        if(!root->left && !root->right) v.push_back(root->val);
        leafOrder(root->left,v);
        leafOrder(root->right,v);
    }
    bool sameVector(vector<int>& v1,vector<int>& v2) {
        if(v1.size()!=v2.size()) return false;
        for(int i=0;i<v1.size();i++)
            if(v1[i]!=v2[i]) return false;
        return true;
    }
public:
    bool leafSimilar(TreeNode* root1,TreeNode* root2) {
        vector<int> v1,v2;
        leafOrder(root1,v1);
        leafOrder(root2,v2);
        return sameVector(v1,v2);
    }
};
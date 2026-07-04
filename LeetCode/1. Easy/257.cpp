struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    void pathReader(TreeNode* root,vector<string>& paths,string path) {
        if(!root) return;
        path+=to_string(root->val);
        if(!root->left && !root->right) {
            paths.push_back(path);
            return;
        }
        path+="->";
        pathReader(root->left,paths,path);
        pathReader(root->right,paths,path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path="";
        pathReader(root,paths,path);
        return paths;
    }
};
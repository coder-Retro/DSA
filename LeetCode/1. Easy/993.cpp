struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int xD,yD;
    TreeNode *xP,*yP;
    void dfs(TreeNode* root,TreeNode* P,int x,int y,int depth) {
        if(!root) return;
        else if(root->val==x) { xD=depth; xP=P; }
        else if(root->val==y) { yD=depth; yP=P; }
        if(xD!=-1 && yD!=-1) return;
        depth++;
        dfs(root->left,root,x,y,depth);
        dfs(root->right,root,x,y,depth);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        xD=yD=-1;
        xP=yP=nullptr;
        dfs(root,nullptr,x,y,0);
        return(xD==yD && xP!=yP);
    }
};
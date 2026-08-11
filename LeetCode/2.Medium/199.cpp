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
SC: O(d), d = depth of recursion
*/

class Solution {
    void dfs(TreeNode* root,vector<int>& rS,int currD,int& maxD) {
        if(!root) return;
        if(currD>maxD) { rS.push_back(root->val); maxD=currD; }
        dfs(root->right,rS,currD+1,maxD);
        dfs(root->left,rS,currD+1,maxD);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSide;
        int maxD=0;
        dfs(root,rightSide,1,maxD);
        return rightSide;
    }
};
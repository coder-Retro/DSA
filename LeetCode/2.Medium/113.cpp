#include<vector>
using namespace std;

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
Approach: Recursion / DFS / Backtracking
TC: O(n)
SC: O(n)
*/

class Solution {
    void dfs(TreeNode* root,vector<vector<int>>& pS,vector<int>& p,int tS) {
        if(!root) return;
        tS-=root->val;
        p.push_back(root->val);
        if(!root->left && !root->right && !tS) pS.push_back(p);
        else {
            dfs(root->left,pS,p,tS);
            dfs(root->right,pS,p,tS);
        }
        p.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> p;
        dfs(root,paths,p,targetSum);
        return paths;
    }
};
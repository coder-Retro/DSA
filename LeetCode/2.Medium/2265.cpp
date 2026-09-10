#include<iostream>
#include<utility>
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
Approach: Recursion / DFS
TC: O(n)
SC: O(h), h = height of tree
*/

class Solution {
    pair<int,int> dfs(TreeNode* root,int& ans) {
        if(!root) return {0,0};
        auto [LSum,LNodes]=dfs(root->left,ans);
        auto [RSum,RNodes]=dfs(root->right,ans);
        int sum=LSum+RSum+root->val;
        int nodes=LNodes+RNodes+1;
        if(sum/nodes==root->val) ans++;
        return {sum,nodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};
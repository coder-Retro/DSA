#include<algorithm>
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
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int lH=dfs(root->left);
        if(lH==-1) return -1;
        int rH=dfs(root->right);
        if(rH==-1) return -1;
        if(abs(lH-rH)>1) return -1;
        return max(lH,rH)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }
};
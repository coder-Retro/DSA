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
    void depthCount(TreeNode* root,int depth,int& minD) {
        if(!root) return;
        depth++;
        if(depth>=minD) return;
        if(!root->left && !root->right) {
            minD=min(minD,depth);
            return;
        }
        depthCount(root->left,depth,minD);
        depthCount(root->right,depth,minD);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int minD=INT_MAX;
        depthCount(root,0,minD);
        return minD;
    }
};
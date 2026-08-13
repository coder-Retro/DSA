#include<vector>
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
Approach: Rercusion / DFS / Sorting
TC: O(n log n)
SC: O(n)
*/

class Solution {
    vector<int> ordered;
    void inOrder(TreeNode* root,vector<int>& ordered) {
        if(!root) return;
        inOrder(root->left,ordered);
        ordered.push_back(root->val);
        inOrder(root->right,ordered);
    }
    void fixTree(TreeNode* root,int& index) {
        if(!root) return;
        fixTree(root->left,index);
        root->val=ordered[index++];
        fixTree(root->right,index);
    }
public:
    void recoverTree(TreeNode* root) {
        inOrder(root,ordered);
        sort(ordered.begin(),ordered.end());
        int index=0;
        fixTree(root,index);
    }
};
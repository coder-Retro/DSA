#include<unordered_set>
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
Approach: Hashing / DFS
TC: O(n)
SC: O(n)
*/

class Solution {
    unordered_set<int> seenVals;
    bool dfs(TreeNode* root,int k,unordered_set<int>& seen) {
        if(!root) return false;
        if(seen.count(k-root->val)) return true;
        seen.insert(root->val);
        return dfs(root->left,k,seen) || dfs(root->right,k,seen);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return dfs(root,k,seenVals);
    }
};
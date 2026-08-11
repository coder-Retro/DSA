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
Approach: Iterative Queue / BFS / Two Pointers
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> v;
            int s=q.size();
            for(int i=0;i<s;i++) {
                TreeNode* node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(v);
        }
        for(int i=0,j=ans.size()-1;i<j;i++,j--) swap(ans[i],ans[j]);
        return ans;
    }
};
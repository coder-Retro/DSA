#include<vector>
#include<deque>
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
Approach: Iterative Deque / BFS
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        dq.push_front(root);
        bool forward=true;
        while(!dq.empty()) {
            vector<int> v;
            int s=dq.size();
            for(int i=0;i<s;i++) {
                TreeNode* node;
                if(forward) {
                    node=dq.front(); dq.pop_front();
                    if(node->left)  dq.push_back(node->left);
                    if(node->right) dq.push_back(node->right);
                } else {
                    node=dq.back(); dq.pop_back();
                    if(node->right) dq.push_front(node->right);
                    if(node->left)  dq.push_front(node->left);
                }
                v.push_back(node->val);
            }
            ans.push_back(v);
            forward=!forward;
        }
        return ans;
    }
};
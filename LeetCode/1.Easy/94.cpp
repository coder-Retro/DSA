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
Approach: Morris InOrder Traversal / Iteration
TC: O(n)
SC: O(1)
*/

class Solution {
    vector<int> morrisInOrder(TreeNode* root) {
        vector<int> vals;
        TreeNode* curr=root;
        while(curr) {
            if(!curr->left) {
                vals.push_back(curr->val);
                curr=curr->right;
            } else {
                TreeNode* pred=curr->left;
                while(pred->right && pred->right!=curr) 
                    pred=pred->right;
                if(!pred->right) {
                    pred->right=curr;
                    curr=curr->left;
                } else {
                    pred->right=nullptr;
                    vals.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return vals;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        return morrisInOrder(root);
    }
};
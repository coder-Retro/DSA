#include<vector>
using namespace std;

// Helper Definitions & Functions
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Approach: Morris PreOrder Traversal / Iteration
TC: O(n)
SC: O(1)
*/

class Solution {
    vector<int> morrisPreOrder(TreeNode* root) {
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
                    vals.push_back(curr->val);
                    pred->right=curr;
                    curr=curr->left;
                } else {
                    pred->right=nullptr;
                    curr=curr->right;
                }
            }
        }
        return vals;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        return morrisPreOrder(root);
    }
};
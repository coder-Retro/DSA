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
Approach: Morris InOrder Traversal / Iteration / DFS
TC: O(n)
SC: O(1)
*/

class Solution {
    TreeNode* morrisInOrder(TreeNode* root) {
    TreeNode* curr=root;
    TreeNode* prev=nullptr;
    TreeNode* newRoot=nullptr;
    while(curr) {
        if(!curr->left) {
            if(prev) prev->right=curr;
            prev=curr;
            if(!newRoot) newRoot=prev;
            curr=curr->right;
        } else {
            // Finding InOrder Predecessor
            TreeNode* pred=curr->left;
            while(pred->right && pred->right!=curr) 
                pred=pred->right;
            if(!pred->right) {
                pred->right=curr; // Creating Thread
                curr=curr->left;
            } else {
                prev->right=curr;
                curr->left=nullptr;
                prev=curr;
                curr=curr->right;
            }
        }
    }
    return newRoot;
}
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;
        return morrisInOrder(root);
    }
};
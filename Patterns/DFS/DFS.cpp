#include<iostream>
using namespace std;

/*
Depth First Search (DFS):
Depth First Search is a pattern, used in the cases where the
problem branches into multiple paths and the solution flows
till the end of one branch before going into the other branch,
a good example of this would be the pre, in and post order
traversals of a Binary Tree. These traversals enter a branch
and keep dropping down towards leaf Nodes before they enter
the next branch. In contrast there is level order traversal
which is an example of BFS, which stands for Breadth First
Search. BFS and DFS are two sides of the same coin - they
just work differently.
*/

// TreeNode Definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// DFS Functions
void dfs_preOrder(TreeNode* root) {
    if(!root) return;
    cout<<root->val<<" ";
    dfs_preOrder(root->left);
    dfs_preOrder(root->right);
}
void dfs_inOrder(TreeNode* root) {
    if(!root) return;
    dfs_inOrder(root->left);
    cout<<root->val<<" ";
    dfs_inOrder(root->right);
}
void dfs_postOrder(TreeNode* root) {
    if(!root) return;
    dfs_postOrder(root->left);
    dfs_postOrder(root->right);
    cout<<root->val<<" ";
}
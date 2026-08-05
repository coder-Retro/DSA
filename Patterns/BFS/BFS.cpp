#include<iostream>
#include<queue>
using namespace std;

/*
Breadth First Search (BFS):
Breadth First Search is a pattern, used in the cases where the
problem branches into multiple paths and the solution flows
level by level on branches before exploring the next levels,
a good example of this would be the level order traversal of
a Binary Tree. This traversals explores level 1 of all branches,
then it drops down to level two and so on. It doesn't look
for the leaf Nodes, instead it works by precomputing the length
of each level to decide when it needs to stop and drop to next.
In contrast there are pre, in and post order traversals
which are examples of DFS, which stands for Depth First
Search. BFS and DFS are two sides of the same coin - they
just work differently. BFS works by using an iterative queue.
*/

// TreeNode Definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BFS Function
void bfs_levelOrder(TreeNode* root) {
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int s=q.size();
        for(int i=0;i<s;i++) {
            TreeNode* node=q.front();
            q.pop();
            cout<<node->val<<" ";
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout<<'\n';
    }
}
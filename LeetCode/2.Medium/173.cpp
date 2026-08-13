#include<stack>
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
Constructor:
Approach: Stack Winding
TC: O(h), h = height of tree
SC: O(h), h = height of tree

next:
Approach: Stack Unwinding & Winding
TC: O(1) amortized, O(h) worst-case for a single call
SC: O(h), h = height of tree

hasNext:
Approach: Stack Check
TC: O(1)
SC: O(1)
*/

class BSTIterator {
    stack<TreeNode*> st;
    void pushLeftBranch(TreeNode* node) {
        while(node) {
            st.push(node);
            node=node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeftBranch(root);
    }
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(node->right) pushLeftBranch(node->right);
        return node->val;
    }
    bool hasNext() {
        return !st.empty();
    }
};
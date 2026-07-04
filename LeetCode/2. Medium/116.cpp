
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
    void traverseAndPopulate(Node* root) {
        if(!root || !root->left) return;
        // Connecting Left Child To Right Child
        root->left->next=root->right;
        // Connecting Subtrees
        if(root->next)
            root->right->next=root->next->left;
        // Recurrsing on Subtrees
        traverseAndPopulate(root->left);
        traverseAndPopulate(root->right); 
    }
public:
    Node* connect(Node* root) {
        traverseAndPopulate(root);
        return root;
    }
};
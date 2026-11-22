// Helper Definition & Functions
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

/*
Approach: BFS / Next Pointer Traversal
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* curr=root;
        while(curr) {
            Node dummy;
            Node* run=&dummy;
            while(curr) {
                if(curr->left) {
                    run->next=curr->left;
                    run=run->next;
                }
                if(curr->right) {
                    run->next=curr->right;
                    run=run->next;
                }
                curr=curr->next;
            }
            curr=dummy.next;
        }
        return root;
    }
};
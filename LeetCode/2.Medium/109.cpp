// Helper Definition & Functions
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Approach: Recursion / Divide And Conquer / Slow & Fast Pointer
TC: O(n log n)
SC: O(log n)
*/

class Solution {
    TreeNode* makeBST(ListNode* head,ListNode* end) {
        if(head==end) return nullptr;
        ListNode *slow=head,*fast=head;
        while(fast!=end && fast->next!=end) {
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* node=new TreeNode(slow->val);
        node->left=makeBST(head,slow);
        node->right=makeBST(slow->next,end);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return makeBST(head,nullptr);
    }
};
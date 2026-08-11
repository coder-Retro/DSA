#include<iostream>
#include<initializer_list>
using namespace std;

// Helper Definitions & Functions
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* makeList(initializer_list<int> lis) {
    ListNode dummy(0);
    ListNode* temp=&dummy;
    for(int i:lis) {
        temp->next=new ListNode(i);
        temp=temp->next;
    }
    return dummy.next;
}
void printList(ListNode* head) {
    while(head) {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"NULL\n";
}
void deleteList(ListNode*& head) {
    while(head) {
        ListNode* target=head;
        head=head->next;
        delete target;
    }
}

/*
Approach: Copy Elimination
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* target=node->next;
        node->val=target->val;
        node->next=target->next;
        delete target;
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({4,5,1,9});
    int targetValue=5;
    ListNode* target=head;
    while(target->val!=targetValue) target=target->next;
    obj.deleteNode(target);
    printList(head);
    deleteList(head);
    return 0;
}
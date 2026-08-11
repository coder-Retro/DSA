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
Approach: Slow & Fast Pointers
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode *slow=&dummy,*fast=&dummy;
        while(n--) fast=fast->next;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* target=slow->next;
        slow->next=target->next;
        delete target;
        return dummy.next;
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({1,2,3,4,5,6,7,8,9,10});
    printList(head);
    head=obj.removeNthFromEnd(head,5);
    printList(head);
    deleteList(head);
    return 0;
}
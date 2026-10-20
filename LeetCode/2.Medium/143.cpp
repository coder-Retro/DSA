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
Approach: Merge Sort
TC: O(n log n)
SC: O(log n), depth of recursion
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        // Find Middle
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=nullptr;
        // Reverse Second Half
        ListNode* prev=nullptr;
        ListNode* curr=mid;
        while(curr) {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        // Merge Both
        ListNode dummy;
        ListNode* tail=&dummy;
        ListNode* l1=head;
        ListNode* l2=prev;
        bool flag=true;
        while(l1 || l2) {
            if(flag) { tail->next=l1; l1=l1->next; }
            else     { tail->next=l2; l2=l2->next; }
            tail=tail->next;
            flag=!flag;
        }
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({1,2,3,4,5});
    cout<<"Raw List       : ";
    printList(head);
    obj.reorderList(head);
    cout<<"Reordered List : ";
    printList(head);
    deleteList(head);
    return 0;
}
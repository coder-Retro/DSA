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
    ListNode* split(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=nullptr;
        return mid;
    }
    ListNode* merge(ListNode* l1,ListNode* l2) {
        ListNode dummy;
        ListNode* tail=&dummy;
        while(l1 && l2) {
            if(l1->val<l2->val) { tail->next=l1; l1=l1->next; }
            else                { tail->next=l2; l2=l2->next; }
            tail=tail->next;
        }
        tail->next=l1?l1:l2;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid=split(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return merge(left,right);
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({5,4,3,2,1});
    cout<<"Raw List : ";
    printList(head);
    head=obj.sortList(head);
    cout<<"Sorted List : ";
    printList(head);
    deleteList(head);
    return 0;
}
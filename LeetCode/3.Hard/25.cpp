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
Approach: Three Pointer In-Place Reversal
TC: O(n)
SC: O(1)
*/

class Solution {
    ListNode* reverseList(ListNode* start,ListNode* end) {
        ListNode* prev=end;
        ListNode* curr=start->next;
        while(curr!=end) {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        ListNode dummy(0,head);
        ListNode* groupPrev=&dummy;
        while(true) {
            ListNode* end=groupPrev;
            for(int i=0;i<k;i++) {
                end=end->next;
                if(!end) return dummy.next;
            }
            ListNode* groupStart=groupPrev->next;
            ListNode* nextGroup=end->next;
            ListNode* groupHead=reverseList(groupPrev,nextGroup);
            groupPrev->next=groupHead;
            groupStart->next=nextGroup;
            groupPrev=groupStart;
        }
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({1,2,3,4,5});
    printList(head);
    int k=2;
    head=obj.reverseKGroup(head,k);
    printList(head);
    deleteList(head);
    return 0;
}
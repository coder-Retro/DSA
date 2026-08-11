#include<iostream>
#include<unordered_set>
#include<initializer_list>
using namespace std;

// Helper Definitions & Functions
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* makeList(initializer_list<int> l) {
    ListNode dummy(0);
    ListNode* temp=&dummy;
    for(int i:l) {
        temp->next=new ListNode(i);
        temp=temp->next;
    }
    return dummy.next;
}
void intersectAndExtendList(ListNode*& head1,ListNode*& head2,initializer_list<int> l) {
    ListNode* shared=makeList(l);
    if(!head1) head1=shared;
    else {
        ListNode* temp=head1;
        while(temp->next) temp=temp->next;
        temp->next=shared;
    }
    if(!head2) head2=shared;
    else {
        ListNode* temp=head2;
        while(temp->next) temp=temp->next;
        temp->next=shared;
    }
}
void deleteIntersectedLists(ListNode*& head1,ListNode*& head2) {
    unordered_set<ListNode*> nodes;
    for(ListNode* head:{head1,head2})
        while(head) {
            nodes.insert(head);
            head=head->next;
        }
    for(ListNode* node:nodes)
        delete node;
    head1=head2=nullptr;
}

/*
Approach: Hashing 
TC: O(m+n), m and n are sizes of lists
SC: O(min(m,n))
*/

class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while(headA) {
            s.insert(headA);
            headA=headA->next;
        }
        while(headB) {
            if(!s.insert(headB).second) return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};

int main() {
    Solution obj;
    ListNode* l1=makeList({4,1});
    ListNode* l2=makeList({5,6,1});
    intersectAndExtendList(l1,l2,{8,4,5});
    cout<<obj.getIntersectionNode(l1,l2)->val;
    deleteIntersectedLists(l1,l2);
    return 0;
}
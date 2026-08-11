#include<iostream>
#include<set>
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
Approach: Hashing
TC: O(n log n)
SC: O(n)
*/

class Solution {
    ListNode* makelist(multiset<int> s) {
        ListNode dummy(0);
        ListNode* l=&dummy;
        for(int i:s) {
            l->next=new ListNode(i);
            l=l->next;
        }
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        multiset<int> s;
        ListNode* temp=head;
        while(temp) {
            s.insert(temp->val);
            temp=temp->next;
        }
        return makelist(s);
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
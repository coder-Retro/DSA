#include<iostream>
#include<vector>
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
Approach: Pointer Based Search
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode* temp=&dummy;
        temp->next=head;
        ListNode* target;
        int current;
        while(temp->next&&temp->next->next) {
            if(temp->next->val==temp->next->next->val) {
                current=temp->next->val;
                while(temp->next&&temp->next->val==current) {
                    target=temp->next;
                    temp->next=target->next;
                    delete target;
                }
            }
            else temp=temp->next;
        }
        return dummy.next;
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({1,1,1,2,3,4,5,5,6,6,6,7,8,9});
    printList(head);
    head=obj.deleteDuplicates(head);
    printList(head);
    deleteList(head);
    return 0;
}
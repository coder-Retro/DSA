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
Approach: Two Pointers 
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        prev->next = curr;
        while(curr && curr->next) {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return dummy.next;
    }
};

int main() {
    Solution obj;
    ListNode* head = makeList({1,2,3,4});
    printList(head);
    head = obj.swapPairs(head);
    printList(head);
    deleteList(head);
    return 0;
}
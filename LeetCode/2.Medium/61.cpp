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
Approach: Cyclic Transformation / Pointer Manipulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        // Finding tail and size of List
        ListNode* tail=head;
        int size=1;
        while(tail->next) {
            tail=tail->next;
            size++;
        }
        // Converting to Circular Linked List
        tail->next=head;
        // Calculating head travel Distance
        k%=size;
        int steps=size-k;
        // Moving head & tail forward step times
        while(steps--) {
            head=head->next;
            tail=tail->next;
        }
        // Converting back to Singly Linked List
        tail->next=nullptr;
        // Returning head of rotated List
        return head;
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({1,2,3,4,5});
    int shift=2;
    printList(head);
    head=obj.rotateRight(head,shift);
    printList(head);
    deleteList(head);
    return 0;
}
#include<iostream>
#include<initializer_list>
using namespace std;

// Helper Definition & Functions
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* makeList(initializer_list<int> l) {
    ListNode dummy;
    ListNode* temp=&dummy;
    for(int i:l) {
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
    ListNode* middleNode(ListNode* head) {
        // Make Two ListNode Pointers to Head.
        ListNode *slow = head, *fast = head;
        // Move One Pointer 1 Step and Other Pointer 2 Steps.
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Return The 1 Stop Moving Pointer.
        return slow;
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({1,2,3,4,5,6});
    cout<<"List: ";
    printList(head);
    cout<<"Middle Node: "<<obj.middleNode(head)->val;
    deleteList(head);
    return 0;
}
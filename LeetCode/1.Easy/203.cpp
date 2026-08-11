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
    ListNode head(0);
    ListNode* l=&head;
    for(int i:lis) {
        l->next=new ListNode(i);
        l=l->next;
    }
    return head.next;
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
Approach: Pointer Traversal
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode Dummy(0);
        Dummy.next=head;
        ListNode* temp=&Dummy;
        ListNode* target;
        while(temp->next) {
            if(temp->next->val==val) {
                target=temp->next;
                temp->next=target->next;
                delete target;
            }
            else temp=temp->next;
        }
        return Dummy.next;
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({1,2,3,4,5,6,7,6,8,6});
    int target=6;
    head=obj.removeElements(head,target);
    printList(head);
    deleteList(head);
    return 0;
}
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
ListNode* makeList(initializer_list<int> lis) {
    ListNode l;
    ListNode* temp=&l;
    for(int i:lis) {
        temp->next=new ListNode(i);
        temp=temp->next;
    }
    return l.next;
}
void printList(ListNode* l) {
    while(l) {
        cout<<l->val<<" ";
        l=l->next;
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
Approach: In-Place Traversal (Linear Search)
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* temp=head;
        while(temp->next!=nullptr) {
            if(temp->val==temp->next->val) {
                ListNode* target=temp->next;
                temp->next=temp->next->next;
                delete target;
            }
            else temp=temp->next;
        }
        return head;
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({1,1,2,2,3,3,4,4,5,5});
    printList(head);
    head=obj.deleteDuplicates(head);
    printList(head);
    deleteList(head);
    return 0;
}
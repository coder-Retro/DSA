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
Approach: Iterative Pointer Manipulation
TC: O(max(m,n)), m and n are sizes of lists
SC: O(max(m,n)), m and n are sizes of lists
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *temp=&dummy;
        int sum=0;
        while(l1 || l2) {
            if(l1) { sum+=l1->val; l1=l1->next; }
            if(l2) { sum+=l2->val; l2=l2->next; }
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            sum/=10;
        }
        if(sum) temp->next=new ListNode(sum);
        return dummy.next;
    }
};

int main() {
    Solution obj;
    ListNode* A=makeList({2,4,3});
    ListNode* B=makeList({5,6,4});
    ListNode* RevSum=obj.addTwoNumbers(A,B);
    cout<<"List A : "; printList(A);
    cout<<"List B : "; printList(B);
    cout<<"Output : "; printList(RevSum);
    deleteList(A);
    deleteList(B);
    deleteList(RevSum);
    return 0;
}
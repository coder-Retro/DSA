#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head,int left,int right) {
        if(!head || !head->next) return head;
        // Setting Dummy Node
        ListNode dummy(0);
        dummy.next=head;
        ListNode* l=&dummy;
        // Finding left-1 Node
        for(int i=1;i<left;i++) l=l->next;
        // Setting Three Pointer Walk
        ListNode* prev=nullptr;
        ListNode* curr=l->next;
        ListNode* next=curr->next;
        // Reversing Range
        for(int i=0;i<right-left;i++) {
            curr->next=prev;
            prev=curr;
            curr=next;
            next=next->next;
        }
        // Connecting Final Gaps
        curr->next=prev;
        l->next->next=next;
        l->next=curr;
        return dummy.next;
    }
};
ListNode* makeList(initializer_list<int> lis)
{
    ListNode l;
    ListNode* temp=&l;
    for(int i:lis)
    {
        temp->next=new ListNode(i);
        temp=temp->next;
    }
    return l.next;
}
void printList(ListNode* l)
{
    while(l)
    {
        cout<<l->val<<" ";
        l=l->next;
    }
}
int main()
{
    Solution s;
    ListNode* head=makeList({1,2,3,4,5});
    int left=2,right=4;
    head=s.reverseBetween(head,left,right);
    printList(head);
    return 0;
}
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* makelist(initializer_list<int> lis) {
    ListNode dummy(0);
    ListNode* l=&dummy;
    for(int i:lis) {
        l->next=new ListNode(i);
        l=l->next;
    }
    return dummy.next;
}
void print(ListNode* head) {
    while(head) {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<'\n';
}

/*
Approach: Three Pointers
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head,int left,int right) {
        if(!head || !head->next) return head;
        if(left==right) return head;
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
int main() {
    Solution obj;
    ListNode* head=makelist({1,2,3,4,5});
    int left=2;
    int right=4;
    head=obj.reverseBetween(head, left, right);
    print(head);
    return 0;
}
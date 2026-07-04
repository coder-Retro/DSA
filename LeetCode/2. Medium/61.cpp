#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* makelist(initializer_list<int> lis)
{
    ListNode dummy(0);
    ListNode* l=&dummy;
    for(int i:lis)
    {
        l->next=new ListNode(i);
        l=l->next;
    }
    return dummy.next;
}
void print(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<'\n';
}
class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        // Finding tail and size of List
        ListNode* tail=head;
        int size=1;
        while(tail->next)
        {
            tail=tail->next;
            size++;
        }
        // Converting to Circular Linked List
        tail->next=head;
        // Calculating head travel Distance
        k%=size;
        int steps=size-k;
        // Moving head & tail forward step times
        while(steps--)
        {
            head=head->next;
            tail=tail->next;
        }
        // Converting back to Singly Linked List
        tail->next=nullptr;
        // Returning head of rotated List
        return head;
    }
};
int main()
{
    Solution s;
    ListNode* l=makelist({1,2,3,4,5});
    int shift=2;
    print(l);
    l=s.rotateRight(l,shift);
    print(l);
    return 0;
}
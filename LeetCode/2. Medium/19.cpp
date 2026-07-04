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
ListNode* makeList(initializer_list<int> lis)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int target=0;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* temp=&dummy;
        while(temp->next)
        {
            target++;
            temp=temp->next;
        }
        target=target-n;
        ListNode* del;
        temp=&dummy;
        while(target && temp->next)
        {
            target--;
            temp=temp->next;
        }
        del=temp->next;
        temp->next=del->next;
        delete del;
        return dummy.next;
    }
};
int main()
{
    Solution s;
    ListNode* l=makeList({1,2,3,4,5,6,7,8,9,10});
    print(l);
    l=s.removeNthFromEnd(l,5);
    print(l);
    return 0;
}
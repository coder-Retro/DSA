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
    ListNode head(0);
    ListNode* l=&head;
    for(int i:lis)
    {
        l->next=new ListNode(i);
        l=l->next;
    }
    return head.next;
}
void print(ListNode* l)
{
    while(l)
    {
        cout<<l->val<<" ";
        l=l->next;
    }
    cout<<'\n';
}
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode Dummy(0);
        Dummy.next=head;
        ListNode* temp=&Dummy;
        ListNode* target;
        while(temp && temp->next)
        {
            if(temp->next->val==val)
            {
                target=temp->next;
                temp->next=target->next;
                delete target;
            }
            else
                temp=temp->next;
        }
        return Dummy.next;
    }
};
int main()
{
    Solution s;
    ListNode* l=makeList({1,2,3,4,5,6,7,6,8,6});
    print(l);
    l=s.removeElements(l,6);
    print(l);
    return 0;
}
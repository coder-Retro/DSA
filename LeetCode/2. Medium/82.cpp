#include<iostream>
#include<vector>
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode* temp=&dummy;
        temp->next=head;
        ListNode* target;
        int current;
        while(temp->next&&temp->next->next)
        {
            if(temp->next->val==temp->next->next->val)
            {
                current=temp->next->val;
                while(temp->next&&temp->next->val==current)
                {
                    target=temp->next;
                    temp->next=target->next;
                    delete target;
                }
            }
            else
                temp=temp->next;
        }
        return dummy.next;
    }
};
int main()
{
    Solution s;
    ListNode* head=makelist({1,1,1,2,3,4,5,5,6,6,6,7,8,9});
    print(head);
    head=s.deleteDuplicates(head);
    print(head);
    return 0;
}
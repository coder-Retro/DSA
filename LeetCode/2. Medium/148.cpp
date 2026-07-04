#include<iostream>
#include<set>
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
class Solution {
    ListNode* makelist(multiset<int> s)
    {
        ListNode dummy(0);
        ListNode* l=&dummy;
        for(int i:s)
        {
            l->next=new ListNode(i);
            l=l->next;
        }
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        multiset<int> s;
        ListNode* temp=head;
        while(temp)
        {
            s.insert(temp->val);
            temp=temp->next;
        }
        return makelist(s);
    }
};
int main()
{
    Solution s;
    ListNode* l=makelist({5,4,3,2,1});
    cout<<"Raw List : ";
    print(l);
    l=s.sortList(l);
    cout<<"Sorted List : ";
    print(l);
    return 0;
}
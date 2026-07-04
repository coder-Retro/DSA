#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode list3;
        ListNode* temp=&list3;
        while(list1&&list2)
        {
            if(list1->val<=list2->val)
            {
                temp->next=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        temp->next=list1?list1:list2;
        return list3.next;
    }
};
int main()
{
    Solution s;
    ListNode* l1=makeList({1,2,4});
    ListNode* l2=makeList({1,3,4});
    ListNode* l3=s.mergeTwoLists(l1,l2);
    printList(l3);
    return 0;
}
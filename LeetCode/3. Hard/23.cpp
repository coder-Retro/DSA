#include<iostream>
#include<vector>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> s;
        ListNode* temp;
        for(int i=0;i<lists.size();i++)
        {
            temp=lists[i];
            while(temp)
            {
                s.insert(temp->val);
                temp=temp->next;
            }
        }
        return makelist(s);
    }
};
int main()
{
    Solution s;
    vector<ListNode*> lists;
    ListNode* lA=makelist({1,4,5});
    ListNode* lB=makelist({1,3,4});
    ListNode* lC=makelist({2,6});
    lists.push_back(lA);
    lists.push_back(lB);
    lists.push_back(lC);
    ListNode* merged=s.mergeKLists(lists);
    print(merged);
    return 0;
}
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
ListNode* makelist(initializer_list<int> l)
{
    ListNode dummy(0);
    ListNode* temp=&dummy;
    for(int i:l)
    {
        temp->next=new ListNode(i);
        temp=temp->next;
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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *temp=&dummy;
        int sum=0;
        while(l1 || l2)
        {
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            sum/=10;
        }
        if(sum)
            temp->next=new ListNode(sum);
        return dummy.next;
    }
};
int main()
{
    Solution s;
    ListNode* A=makelist({2,4,3});
    ListNode* B=makelist({5,6,4});
    ListNode* RevSum=s.addTwoNumbers(A,B);
    cout<<"List A : "; print(A);
    cout<<"List B : "; print(B);
    cout<<"Output : "; print(RevSum);
    return 0;
}
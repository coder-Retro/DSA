#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* target=node->next;
        node->val=target->val;
        node->next=target->next;
        delete target;
    }
};
ListNode* makeList(initializer_list<int> lis) {
    ListNode dummy(0);
    ListNode* temp=&dummy;
    for(int i:lis) {
        temp->next=new ListNode(i);
        temp=temp->next;
    }
    return dummy.next;
}
int main() {
    Solution s;
    ListNode* lis=makeList({4,5,1,9});
    int targetValue=5;
    ListNode* target=lis;
    while(target->val!=targetValue) target=target->next;
    s.deleteNode(target);
    while(lis) {
        cout<<lis->val<<" ";
        lis=lis->next;
    }
    return 0;
}
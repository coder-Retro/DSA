#include<iostream>
#include<unordered_set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> s;
        while(headA)
        {
            s.insert(headA);
            headA=headA->next;
        }
        while(headB)
        {
            if(!s.insert(headB).second) return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};
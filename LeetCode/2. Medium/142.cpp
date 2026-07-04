#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(!fast || !fast->next) return nullptr;
        slow=head;
        while(slow!=fast) {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
int main() {
    Solution s;
    // Making ListNodes;
    ListNode* n1=new ListNode(1);
    ListNode* n2=new ListNode(2);
    ListNode* n3=new ListNode(3);
    ListNode* n4=new ListNode(4);
    // Connecting ListNodes
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    // Forming Cycle
    n4->next=n2;
    // Calling Function
    ListNode* cycleNode=s.detectCycle(n1);
    // Checking output
    if(cycleNode)
        cout<<"Cycle Detected At Pos : "<<cycleNode->val;
    else
        cout<<"No Cycle Detected";
    return 0;
}
#include<iostream>
#include<unordered_set>
#include<initializer_list>
using namespace std;

// Helper Definition & Functions
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* makeCycleList(initializer_list<int> l, size_t index) {
    ListNode dummy(0);
    ListNode* temp=&dummy;
    ListNode* targetNode=nullptr;
    for(int i:l) {
        temp->next=new ListNode(i);
        temp=temp->next;
        if(!index) targetNode=temp;
        index--;
    }
    temp->next=targetNode;
    return dummy.next;
}
void deleteCycleList(ListNode*& head) {
    unordered_set<ListNode*> visited;
    while(head && !visited.contains(head)) {
        visited.insert(head);
        ListNode* target=head;
        head=head->next;
        delete target;
    }
    head=nullptr;
}

/*
Approach: Slow & Fast Pointers / Floyd's Cycle Detection
TC: O(n)
SC: O(1)
*/

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
    Solution obj;
    ListNode* head=makeCycleList({3,2,0,-4},1);
    ListNode* cycleNode=obj.detectCycle(head);
    // Checking output
    if(cycleNode) cout<<"Cycle Detected At ListNode->val: "<<cycleNode->val;
    else          cout<<"No Cycle Detected";
    deleteCycleList(head);
    return 0;
}
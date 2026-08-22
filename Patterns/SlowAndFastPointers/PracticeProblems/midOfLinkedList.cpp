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
Problem Statement:
You are required to write a function which takes
a "ListNode* head" passed by value. The function
should return a pointer to ListNode from where
the cycle begins.

Constraints:
1. Your solution should be O(1) in space.
2. You can only use two loops (not nested).
3. You can't use any nested loops.
*/

class SandFpointers {
public:
    ListNode* detectCycle(ListNode* head) {
        // Your Code Here
    }
};

int main() {
    SandFpointers obj;
    ListNode* head=makeCycleList({3,2,0,-4},1);
    cout<<obj.detectCycle(head)->val;
    deleteCycleList(head);
    return 0;
}
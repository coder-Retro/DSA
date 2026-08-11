#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Helper Definitions & Functions
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
void printList(ListNode* head) {
    while(head) {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"NULL\n";
}
void deleteList(ListNode*& head) {
    while(head) {
        ListNode* target=head;
        head=head->next;
        delete target;
    }
}

/*
Approach: Min Heap
TC: O(n log k), k = number of lists
SC: O(k), k = number of lists
*/

class Solution {
    struct Compare {
        bool operator()(ListNode* a,ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> minHeap;
        for(ListNode* l:lists)
            if(l) minHeap.push(l);
        ListNode dummy;
        ListNode* tail=&dummy;
        while(!minHeap.empty()) {
            ListNode* node=minHeap.top();
            minHeap.pop();
            tail->next=node;
            tail=tail->next;
            if(node->next)
                minHeap.push(node->next);
        }
        return dummy.next;
    }
};

int main() {
    Solution obj;
    vector<ListNode*> lists;
    ListNode* lA=makeList({1,4,5});
    ListNode* lB=makeList({1,3,4});
    ListNode* lC=makeList({2,6});
    lists.push_back(lA);
    lists.push_back(lB);
    lists.push_back(lC);
    ListNode* merged=obj.mergeKLists(lists);
    printList(merged);
    deleteList(merged);
    return 0;
}
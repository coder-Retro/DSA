#include<iostream>
#include<queue>
#include<initializer_list>
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
TC: O(n log n)
SC: O(n)
*/

class Solution {
    struct Compare {
        bool operator()(ListNode* a,ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* sortList(ListNode* head) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> minHeap;
        ListNode* temp=head;
        while(temp) {
            minHeap.push(temp);
            temp=temp->next;
        }
        ListNode dummy;
        temp=&dummy;
        while(!minHeap.empty()) {
            temp->next=minHeap.top();
            minHeap.pop();
            temp=temp->next;
        }
        temp->next=nullptr;
        return dummy.next;
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({5,4,3,2,1});
    cout<<"Raw List : ";
    printList(head);
    ListNode* sortedHead=obj.sortList(head);
    cout<<"Sorted List : ";
    printList(sortedHead);
    deleteList(head);
    return 0;
}
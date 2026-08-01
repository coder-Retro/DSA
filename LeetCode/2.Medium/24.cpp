#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* makeList(initializer_list<int> l) {
    ListNode dummy;
    ListNode* temp = &dummy;
    for(int i:l) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    return dummy.next;
}
void printList(ListNode* head) {
    while(head) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<'\n';
}

/*
Approach: Two Pointers 
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        prev->next = curr;
        while(curr && curr->next) {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return dummy.next;
    }
};
int main() {
    Solution obj;
    ListNode* head = makeList({1,2,3,4});
    ListNode* ans = obj.swapPairs(head);
    printList(ans);
    return 0;
}
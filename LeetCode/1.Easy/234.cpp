#include<iostream>
#include<initializer_list>
using namespace std;

// Helper Definition & Functions
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* makeList(initializer_list<int> l) {
    ListNode dummy(0);
    ListNode* temp=&dummy;
    for(int i:l) {
        temp->next=new ListNode(i);
        temp=temp->next;
    }
    return dummy.next;
}
void deleteList(ListNode*& head) {
    while(head) {
        ListNode* target=head;
        head=head->next;
        delete target;
    }
}

/*
Approach: Slow & Fast Pointers / In-Place Reversal / Two Pointers
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Find Middle (Slow & Fast Pointers)
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        // Reverse Second Half (Three Pointers)
        ListNode *prev=nullptr;
        ListNode *next=slow->next;
        while(next) {
            slow->next=prev;
            prev=slow;
            slow=next;
            next=next->next;
        }
        slow->next=prev;
        // Compare (Head to Mid) with (Mid to End)
        ListNode *revHead=slow;
        bool result=true;
        prev=head;
        while(slow) {
            // Difference Detected (Not Palindrome)
            if(prev->val!=slow->val) {
                result=false;
                break;
            }
            prev=prev->next;
            slow=slow->next;
        }
        // Restore Second Half (Reverse It Back)
        prev=nullptr;
        while(revHead) {
            next=revHead->next;
            revHead->next=prev;
            prev=revHead;
            revHead=next;
        }
        return result;
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({1,2,3,4,3,2,1});
    cout<<(obj.isPalindrome(head)?"true":"false");
    deleteList(head);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
        prev=head;
        while(slow) {
            // Difference Detected (Not Palindrome)
            if(prev->val!=slow->val) return false;
            prev=prev->next;
            slow=slow->next;
        }
        // No Difference Detected (Palindrome)
        return true;
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
    ListNode* head=makeList({1,2,3,4,3,2,1});
    if(s.isPalindrome(head))
        cout<<"List is Palindrome";
    else
        cout<<"List is not Palindrome";
    return 0;
}
#include<iostream>
#include<vector>
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
Approach: Min-Max Tracking
TC: O(n)
SC: O(n)
*/

class Solution {
    vector<int> criticalPoints(ListNode* head) {
        vector<int> cPs;
        int prev=head->val;
        ListNode* temp=head->next;
        int idx=2;
        while(temp->next) {
            int next=temp->next->val;
            if(temp->val < prev && temp->val < next)
                cPs.push_back(idx);
            if(temp->val > prev && temp->val > next)
                cPs.push_back(idx);
            prev=temp->val;
            temp=temp->next;
            idx++;
        }
        return cPs;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};
        vector<int> cps=criticalPoints(head);
        if(cps.size()<2) return {-1,-1};
        int minD=100000;
        for(int i=0;i<cps.size()-1;i++)
            minD=min(minD,cps[i+1]-cps[i]);
        int maxD=(cps.back()-cps[0]);
        return {minD,maxD};
    }
};

int main() {
    Solution obj;
    ListNode* head=makeList({5,3,1,2,5,1,2});
    for(int i:obj.nodesBetweenCriticalPoints(head)) cout<<i<<" ";
    deleteList(head);
    return 0;
}
#include<iostream>
#include<unordered_map>
#include<initializer_list>
using namespace std;

// Helper Definitions & Functions
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val): val(_val), next(nullptr), random(nullptr) {}
};
Node* makeList(initializer_list<int> lis,initializer_list<int> ran) {
    unordered_map<int,Node*> log;
    Node dummy(0);
    Node* temp=&dummy;
    int idx=0;
    for(int i:lis) {
        temp->next=new Node(i);
        temp=temp->next;
        log[idx++]=temp;
    }
    temp=dummy.next;
    for(int i:ran) {
        if(i!=-1) temp->random=log[i];
        temp=temp->next;
    }
    return dummy.next;
}
void printList(Node* head) {
    cout<<"[";
    while(head) {
        cout<<"[";
        cout<<head->val<<",";
        if(head->random) cout<<head->random->val;
        else             cout<<"null";
        cout<<"]";
        if(head->next) cout<<",";
        head=head->next;
    }
    cout<<"]\n";
}
void deleteList(Node*& head) {
    while(head) {
        Node* target=head;
        head=head->next;
        delete target;
    }
}

/*
Approach: Hashing / Deep Copy
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Making Basic Linked List
        unordered_map<Node*,Node*> copied;
        Node dummy(0);
        Node* tail=&dummy;
        Node* curr=head;
        while(curr) {
            tail->next=new Node(curr->val);
            copied[curr]=tail->next;
            tail=tail->next;
            curr=curr->next;
        }
        // Connecting Random Pointers
        curr=head;
        tail=dummy.next;
        while(curr) {
            tail->random=copied[curr->random];
            curr=curr->next;
            tail=tail->next;
        }
        return dummy.next;
    }
};

int main() {
    Solution obj;
    Node* head=makeList({7,13,11,10,1},{-1,0,4,2,0});
    Node* copy=obj.copyRandomList(head);
    cout<<"Input:  \n";  printList(head);
    cout<<"Output: \n"; printList(copy);
    deleteList(head);
    deleteList(copy);
    return 0;
}
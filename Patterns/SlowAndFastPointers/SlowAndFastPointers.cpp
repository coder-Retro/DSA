#include<iostream>
using namespace std;

/*
Slow And Fast Pointers:
Slow and Fast Pointer is a DSA technique that is primarily
associated with Linked List problems. In this technique we
initialized two ListNode pointers with head of the Linked
List. One is called slow and the other is called fast, as:

ListNode *slow,*fast;
slow=fast=head;

Now both pointers traverse the list using a loop, commonly
while loop. But the movement speeds differ. Slow moves one
Node forward with each iteration and fast moves two Nodes
forward with each iteration. This algorithm is used mainly
for problems like:

1. Palindrom Linked List
2. Linked List Cycle Detection
3. Middle of Linked List
*/

// ListNode Class
class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int val):data(val),next(nullptr){}
};

// Cycle Detection Function
bool cycleExists(ListNode *head){
    ListNode *slow,*fast;
    slow=fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

// Main Function
int main()
{
    // Initializing ListNodes
    ListNode *head=new ListNode(1);
    ListNode *nod1=new ListNode(2);
    ListNode *nod2=new ListNode(3);
    ListNode *nod3=new ListNode(4);
    ListNode *nod4=new ListNode(5);
    ListNode *nod5=new ListNode(6);
    // Making Linked List
    head->next=nod1;
    nod1->next=nod2;
    nod2->next=nod3;
    nod3->next=nod4;
    nod4->next=nod5;
    // Making Cycle
    nod5->next=nod3;
    // Checking Cycle
    if(cycleExists(head))
        cout<<"Cycle Exists";
    else
        cout<<"Cycle Does Not Exist";
    return 0;
}
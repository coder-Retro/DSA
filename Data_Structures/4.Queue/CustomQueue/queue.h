#include<stdexcept>

// ListNode Class
class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int data=0):data(data),next(nullptr){}
};

// Queue Class
class queue {
    ListNode *head,*tail;
public:
    queue(){ head=tail=nullptr; }
    void enqueue(int n) {
        ListNode* newNode=new ListNode(n);
        if(!head) head=tail=newNode;
        else {
            tail->next=newNode;
            tail=newNode;
        }
    }
    int front() {
        if(!head) throw std::runtime_error("Empty");
        else return head->data;
    }
    void dequeue() {
        if(!head) throw std::runtime_error("Empty");
        else if(head==tail){ delete head; head=tail=nullptr;  }
        else {
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }
    }
    bool empty() { return !head; }
    void clear() { while(head) dequeue(); }
    
    ~queue(){ clear(); }
};
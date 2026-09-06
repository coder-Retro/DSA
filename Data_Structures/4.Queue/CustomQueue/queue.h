#include<stdexcept>

template <typename T>
// ListNode Class
class ListNode {
public:
    T data;
    ListNode<T>* next;
    ListNode(T data=0): data(data), next(nullptr) {}
};

template <typename T>
// Queue Class
class Queue {
    ListNode<T>* head;
    ListNode<T>* tail;
    int len;
    void copy(Queue& current, const Queue& other) {
        ListNode<T>* copier=other.head;
        while(copier) {
            current.enqueue(copier->data);
            copier=copier->next;
        }
    }
public:
    Queue(): head(nullptr), tail(nullptr), len(0) {}
    Queue(const Queue& other): head(nullptr), tail(nullptr), len(0) {
        copy(*this, other);
    }
    Queue& operator=(const Queue& other) {
        if(this!=&other) {
            clear();
            copy(*this, other);
        }
        return *this;
    }

    void enqueue(T n) {
        ListNode<T>* newNode=new ListNode<T>(n);
        if(!head) head=tail=newNode;
        else {
            tail->next=newNode;
            tail=newNode;
        }
        len++;
    }
    T front() {
        if(!head) throw std::underflow_error("Queue is empty!\n");
        return head->data;
    }
    void dequeue() {
        if(!head) throw std::underflow_error("Queue is empty!\n");
        ListNode<T>* target=head;
        if(head==tail) head=tail=nullptr;
        else head=head->next;
        delete target;
        len--;
    }
    int size() const { return len; }
    bool empty() const { return !head; }
    void clear() { while(head) dequeue(); }
    
    ~Queue() { clear(); }
};
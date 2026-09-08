#include<stdexcept>

template <typename T>
// Queue Class
class Queue {
    struct Node {
        T data;
        Node* next;
        Node(T data): data(data), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    size_t len;
    void copy(const Queue& other) {
        Node* copier=other.head;
        while(copier) {
            push(copier->data);
            copier=copier->next;
        }
    }
public:
    Queue(): head(nullptr), tail(nullptr), len(0) {}
    Queue(const Queue& other): head(nullptr), tail(nullptr), len(0) {
        copy(other);
    }
    Queue& operator=(const Queue& other) {
        if(this!=&other) {
            clear();
            copy(other);
        }
        return *this;
    }

    void push(T data) {
        Node* newNode=new Node(data);
        if(!head) head=tail=newNode;
        else {
            tail->next=newNode;
            tail=newNode;
        }
        len++;
    }
    void pop() {
        if(!head) throw std::underflow_error("Queue is empty!\n");
        Node* target=head;
        if(head==tail) head=tail=nullptr;
        else head=head->next;
        delete target;
        len--;
    }
    T front() {
        if(!head) throw std::underflow_error("Queue is empty!\n");
        return head->data;
    }
    size_t size() const { return len; }
    bool empty() const { return !head; }
    void clear() { while(head) pop(); }
    
    ~Queue() { clear(); }
};
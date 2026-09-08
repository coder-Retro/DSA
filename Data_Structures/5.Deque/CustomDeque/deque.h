#include<stdexcept>

template<typename T>
// Deque Class
class Deque {
    // Node struct
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T data): data(data), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    size_t len;
    void copy(const Deque<T>& other) {
        Node* copier=other.head;
        while(copier) {
            push_back(copier->data);
            copier=copier->next;
        }
    }
public:
    Deque(): head(nullptr), tail(nullptr), len(0) {}
    Deque(const Deque<T>& other): head(nullptr), tail(nullptr), len(0) {
        copy(other);
    }
    Deque& operator=(const Deque& other) {
        if(this!=&other) {
            clear();
            copy(other);
        }
        return *this;
    }
    T& operator[](size_t pos) {
        if(pos<1 || pos>len) throw std::out_of_range("Invalid Position!\n");
        Node* temp;
        if(pos<len/2) {
            temp=head;
            for(size_t i=1;i<pos;i++) temp=temp->next;
        } else {
            temp=tail;
            for(size_t i=len;i>pos;i--) temp=temp->prev;
        }
        return temp->data;
    }

    void push_front(T data) {
        Node* newNode=new Node(data);
        if(!head) head=tail=newNode;
        else {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        len++;
    }
    void push_back(T data) {
        Node* newNode=new Node(data);
        if(!tail) head=tail=newNode;
        else {
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
        len++;
    }
    void pop_front() {
        if(!head) throw std::underflow_error("Deque is empty!\n");
        Node* target=head;
        if(head==tail) head=tail=nullptr;
        else {
            head=head->next;
            head->prev=nullptr;
        }
        delete target;
        len--;
    }
    void pop_back() {
        if(!tail) throw std::underflow_error("Deque is empty!\n");
        Node* target=tail;
        if(head==tail) head=tail=nullptr;
        else {
            tail=tail->prev;
            tail->next=nullptr;
        }
        delete target;
        len--;
    }
    T front() const {
        if(!head) throw std::underflow_error("Deque is empty!\n");
        return head->data;
    }
    T back() const {
        if(!head) throw std::underflow_error("Deque is empty!\n");
        return tail->data;
    }
    void clear() { while(head) pop_front(); }
    size_t size() const { return len; }
    bool empty() const { return !len; }

    ~Deque() { clear(); }
};
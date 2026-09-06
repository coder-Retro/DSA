#include<stdexcept>

template <typename T>
// ListNode Class
class ListNode{
public:
    T data;
    ListNode* next;
    ListNode(T data): data(data), next(nullptr) {}
};

template <typename T>
// Deque Class
class Deque {
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int len;
    void copy(Deque& current, const Deque& other) {
        ListNode<T>* copier = other.head;
        while (copier) {
            current.push_back(copier->data);
            copier = copier->next;
        }
    }
public:
    Deque(): head(nullptr), tail(nullptr), len(0) {}
    Deque(const Deque& other): head(nullptr), tail(nullptr), len(0) {
        copy(*this, other);
    }
    Deque& operator=(const Deque& other) {
        if(this!=&other) {
            clear();
            copy(*this, other);
        }
        return *this;
    }

    void push_front(T data) {
        ListNode<T>* newNode=new ListNode<T>(data);
        if(!head) head=tail=newNode;
        else {
            newNode->next=head;
            head=newNode;
        }
        len++;
    }
    void push_back(T data) {
        if(!head) { push_front(data); return; }
        tail->next=new ListNode<T>(data);
        tail=tail->next;
        len++;
    }
    void pop_front() {
        if(!head) throw std::underflow_error("Deque is empty!\n");
        ListNode<T>* target=head;
        if(head==tail) head=tail=nullptr;
        else head=head->next;
        delete target;
        len--;
    }
    void pop_back() {
        if(!head) throw std::underflow_error("Deque is empty!\n");
        if(head==tail) { pop_front(); return; }
        ListNode<T>* temp=head;
        while(temp->next!=tail) temp=temp->next;
        tail=temp;
        delete tail->next;
        tail->next=nullptr;
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
    int size() const { return len; }
    bool empty() const { return !len; }
    void clear() { while(head) pop_front(); }

    ~Deque(){ clear(); }
};
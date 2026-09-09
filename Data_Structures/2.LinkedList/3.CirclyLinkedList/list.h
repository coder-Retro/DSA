#include<vector>
#include<utility>
#include<stdexcept>

template <typename T>
class CirclyLinkedList {
    struct Node {
        T data;
        Node* next;
        Node(T data): data(data), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    size_t len;
    void copy(const CirclyLinkedList<T>& other) {
        if(!other.head) return;
        Node* copier=other.head;
        do {
            push_back(copier->data);
            copier=copier->next;
        } while(copier!=other.head);
    }
public:
    CirclyLinkedList(): head(nullptr), tail(nullptr), len(0) {}
    CirclyLinkedList(const CirclyLinkedList<T>& other): head(nullptr), tail(nullptr), len(0) {
        copy(other);
    }
    CirclyLinkedList& operator=(const CirclyLinkedList<T>& other) {
        if(this!=&other) {
            clear();
            copy(other);
        }
        return *this;
    }
    T& operator[](size_t pos) {
        if(pos<1 || pos>len) throw std::out_of_range("Invalid Position!\n");
        Node* temp=head;
        for(size_t i=1;i<pos;i++) temp=temp->next;
        return temp->data;
    }

    void push_front(T data) {
        Node* newNode=new Node(data);
        if(!head) {
            head=tail=newNode;
            newNode->next=newNode;
        } else {
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
        len++;
    }
    void push_back(T data) {
        Node* newNode=new Node(data);
        if(!head) {
            head=tail=newNode;
            newNode->next=newNode;
        } else {
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }
        len++;
    }
    void pop_front() {
        if(!head) throw std::underflow_error("List is empty!\n");
        Node* target=head;
        if(head==tail) head=tail=nullptr;
        else {
            head=head->next;
            tail->next=head;
        }
        delete target;
        len--;
    }
    void pop_back() {
        if(!head) throw std::underflow_error("List is empty!\n");
        Node* target=head;
        if(head==tail) head=tail=nullptr;
        else {
            while(target->next!=tail) target=target->next;
            tail=target;
            target=target->next;
            tail->next=head;
        }
        delete target;
        len--;
    }
    void insert(T data, size_t pos) {
        if(pos<1 || pos>len+1) throw std::out_of_range("Invalid Position!\n");
        if(pos==1) { push_front(data); return; }
        if(pos==len+1) { push_back(data); return; }
        Node* newNode=new Node(data);
        Node* temp=head;
        for(size_t i=1;i<pos-1;i++) temp=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
        len++;
    }
    void remove(size_t pos) {
        if(!head) throw std::underflow_error("List is empty!\n");
        if(pos<1 || pos>len) throw std::out_of_range("Invalid Position!\n");
        if(pos==1) { pop_front(); return; }
        if(pos==len) { pop_back(); return; }
        Node* temp=head;
        for(size_t i=1;i<pos-1;i++) temp=temp->next;
        Node* target=temp->next;
        temp->next=target->next;
        delete target;
        len--;
    }
    size_t find(T data) const {
        if(!head) return 0;
        size_t pos=1;
        Node* temp=head;
        do {
            if(temp->data==data) return pos;
            pos++;
            temp=temp->next;
        } while(temp!=head);
        return 0;
    }
    bool contains(T data) const { return find(data); }
    void reverse() {
        if(!head) return;
        Node* prev=tail;
        Node* curr=head;
        do {
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        } while(curr!=head);
        std::swap(head, tail);
    }
    std::vector<T> values(bool flag=false) const {
        if(!head) return {};
        std::vector<T> vals;
        vals.reserve(len);
        Node* temp=head;
        do {
            vals.push_back(temp->data);
            temp=temp->next;
        } while(temp!=head);
        if(flag) {
            size_t left=0, right=len-1;
            while(left<right) {
                std::swap(vals[left], vals[right]);
                left++,right--;
            }
        }
        return vals;
    }
    T front() const {
        if(!head) throw std::underflow_error("List is empty!\n");
        return head->data;
    }
    T back() const {
        if(!head) throw std::underflow_error("List is empty!\n");
        return tail->data;
    }
    void clear() { while(head) pop_front(); }
    size_t size() const { return len; }
    bool empty() const { return !len; }

    ~CirclyLinkedList() { clear(); }
};
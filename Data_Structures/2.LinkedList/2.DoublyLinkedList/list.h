#include<vector>
#include<stdexcept>

template<typename T>
// Doubly Linked List Class
class DoublyLinkedList {
    // Node struct
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T data): data(data), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int len;
    void copy(const DoublyLinkedList<T>& other) {
        Node* copier=other.head;
        while(copier) {
            push_back(copier->data);
            copier=copier->next;
        }
    }
public:
    DoublyLinkedList(): head(nullptr), tail(nullptr), len(0) {}
    DoublyLinkedList(const DoublyLinkedList<T>& other): head(nullptr), tail(nullptr), len(0) {
        copy(other);
    }
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if(this!=&other) {
            clear();
            copy(other);
        }
        return *this;
    }
    T& operator[](int pos) {
        if(pos<1 || pos>len) throw std::out_of_range("Invalid Position!\n");
        Node* temp;
        if(pos<len/2) {
            temp=head;
            for(int i=1;i<pos;i++) temp=temp->next;
        } else {
            temp=tail;
            for(int i=len;i>pos;i--) temp=temp->prev;
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
        if(!head) throw std::underflow_error("List is empty!\n");
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
        if(!tail) throw std::underflow_error("List is empty!\n");
        Node* target=tail;
        if(head==tail) head=tail=nullptr;
        else {
            tail=tail->prev;
            tail->next=nullptr;
        }
        delete target;
        len--;
    }
    void insert(T data, int pos) {
        if(pos<1 || pos>len+1) throw std::out_of_range("Invalid Position!\n");
        if(pos==1) { push_front(data); return; }
        if(pos==len+1) { push_back(data); return; }
        Node* newNode=new Node(data);
        Node* temp=head;
        for(int i=1;i<pos-1;i++) temp=temp->next;
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next->prev=newNode;
        temp->next=newNode;
        len++;
    }
    void remove(int pos) {
        if(!head) throw std::underflow_error("Empty List!\n");
        if(pos<1 || pos>len) throw std::out_of_range("Invalid Position!\n");
        if(pos==1) { pop_front(); return; }    
        if(pos==len) { pop_back(); return; }
        Node* target=head;
        for(int i=1;i<pos;i++) target=target->next;
        target->prev->next=target->next;
        target->next->prev=target->prev;
        delete target;
        len--;
    }
    int find(T data) const {
        Node* temp=head;
        int pos=1;
        while(temp) {
            if(temp->data==data) return pos;
            temp=temp->next;
            pos++;
        }
        return 0;
    }
    bool contains(T data) const { return find(data); }
    void reverse() {
        Node* curr=head;
        while(curr) {
            Node* prev_temp=curr->prev;
            Node* next_temp=curr->next;
            curr->prev=next_temp;
            curr->next=prev_temp;
            curr=curr->prev;
        }
        curr=tail;
        tail=head;
        head=curr;
    }
    std::vector<T> values(bool flag=false) const {
        std::vector<T> vals(len);
        if(flag) {
            Node* temp=tail;
            for(int i=0;i<len;i++) {
                vals[i]=temp->data;
                temp=temp->prev;
            }
        } else {
            Node* temp=head;
            for(int i=0;i<len;i++) {
                vals[i]=temp->data;
                temp=temp->next;
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
    int size() const { return len; }
    bool empty() const { return !len; }

    ~DoublyLinkedList() { clear(); }
};
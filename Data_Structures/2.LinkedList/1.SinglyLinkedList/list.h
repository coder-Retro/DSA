#include<vector>
#include<utility>
#include<stdexcept>

template<typename T>
// SinglyLinkedList Class
class SinglyLinkedList {
    // Node Struct
    struct Node {
        T data;
        Node* next;
        Node(T data): data(data), next(nullptr) {}
    };
    Node* head; // Points to Front Node of list
    Node* tail; // Points to Back Node of list
    int len;
    void copy(const SinglyLinkedList& other) {
        Node* copier=other.head;
        while(copier) {
            push_back(copier->data);
            copier=copier->next;
        }
    }
public:
    SinglyLinkedList(): head(nullptr), tail(nullptr) ,len(0) {}
    SinglyLinkedList(const SinglyLinkedList& other): head(nullptr), tail(nullptr) ,len(0) {
        copy(other);
    }
    SinglyLinkedList& operator=(const SinglyLinkedList& other) {
        if(this!=&other) {
            clear();
            copy(other);
        }
        return *this;
    }
    T& operator[](int pos) {
        if(pos<1 || pos>len) throw std::out_of_range("Invalid Position!\n");
        Node* temp=head;
        for(int i=1;i<pos;i++) temp=temp->next;
        return temp->data;
    }

    void push_front(T data) {
        Node* newNode=new Node(data);
        if(!head) head=tail=newNode;
        else {
            newNode->next=head;
            head=newNode;
        }
        len++;
    }
    void push_back(T data) {
        if(!head) { push_front(data); return; }
        tail->next=new Node(data);
        tail=tail->next;
        len++;
    }
    void pop_front() {
        if(!head) throw std::underflow_error("List is empty!\n");
        Node* target=head;
        if(head==tail) head=tail=nullptr;
        else head=head->next;
        delete target;
        len--;
    }
    void pop_back() {
        if(!head) throw std::underflow_error("List is empty!\n");
        if(head==tail) { pop_front(); return; }
        Node* temp=head;
        while(temp->next!=tail) temp=temp->next;
        tail=temp;
        delete tail->next;
        tail->next=nullptr;
        len--;
    }
    void insert(T data,int pos) {
        if(pos<1 || pos>len+1) throw std::out_of_range("Invalid Position!\n");
        if(pos==1) { push_front(data); return; }
        if(pos==len+1) { push_back(data); return; }
        Node* newNode= new Node(data);
        Node* temp=head;
        for(int i=1;i<pos-1;i++) temp=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
        len++;
    }
    void remove(int pos) {
        if(!head) throw std::underflow_error("List is empty!\n");
        if(pos<1 || pos>len) throw std::out_of_range("Invalid Position!\n");
        if(pos==1) { pop_front(); return; }
        if(pos==len) { pop_back(); return; }
        Node* temp=head;
        for(int i=1;i<pos-1;i++) temp=temp->next;
        Node* target=temp->next;
        temp->next=target->next;
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
        if(head==tail) return;
        Node* prev=nullptr;
        Node* curr=head;
        while(curr) {
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        tail=head;
        head=prev;
    }
    std::vector<T> values(bool flag=false) const {
        std::vector<T> vals(len);
        Node* temp=head;
        for(int i=0;i<len;i++) {
            vals[i]=temp->data;
            temp=temp->next;
        }
        if(flag) {
            int left=0,right=len-1;
            while(left<right) {
                std::swap(vals[left],vals[right]);
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
    int size() const { return len; }
    bool empty() const { return !len; }

    ~SinglyLinkedList() { clear(); }
};
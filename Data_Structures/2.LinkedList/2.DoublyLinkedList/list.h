#include<vector>
#include<stdexcept>

template<typename T>
// Node Class
class Node {
public:
    T val;
    Node<T>* prev;
    Node<T>* next;
    Node(T val): val(val), prev(nullptr), next(nullptr) {}
};

template<typename T>
// Doubly Linked List Class
class DoublyLinkedList {
    Node<T>* head;
    Node<T>* tail;
    int len;
    void copy(DoublyLinkedList& current, const DoublyLinkedList<T>& other) {
        Node<T>* copier=other.head;
        while(copier) {
            current.putBack(copier->val);
            copier=copier->next;
        }
    }
public:
    DoublyLinkedList(): head(nullptr), tail(nullptr), len(0) {}
    DoublyLinkedList(const DoublyLinkedList<T>& other): head(nullptr), tail(nullptr), len(0) {
        copy(*this, other);
    }
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if(this!=&other) {
            clear();
            copy(*this, other);
        }
        return *this;
    }

    void putFront(T val) {
        Node<T>* newNode=new Node<T>(val);
        if(!head) head=tail=newNode;
        else {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        len++;
    }
    void putBack(T val) {
        Node<T>* newNode=new Node<T>(val);
        if(!tail) head=tail=newNode;
        else {
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
        len++;
    }
    void remFront() {
        if(!head) throw std::underflow_error("List is empty!\n");
        Node<T>* target=head;
        if(head==tail) head=tail=nullptr;
        else {
            head=head->next;
            head->prev=nullptr;
        }
        delete target;
        len--;
    }
    void remBack() {
        if(!tail) throw std::underflow_error("List is empty!\n");
        Node<T>* target=tail;
        if(head==tail) head=tail=nullptr;
        else {
            tail=tail->prev;
            tail->next=nullptr;
        }
        delete target;
        len--;
    }
    void insert(T val, int pos) {
        if(pos<1 || pos>len+1) throw std::out_of_range("Invalid Position!\n");
        if(pos==1) { putFront(val); return; }
        if(pos==len+1) { putBack(val); return; }
        Node<T>* newNode=new Node<T>(val);
        Node<T>* temp=head;
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
        if(pos==1) { remFront(); return; }    
        if(pos==len) { remBack(); return; }
        Node<T>* target=head;
        for(int i=1;i<pos;i++) target=target->next;
        target->prev->next=target->next;
        target->next->prev=target->prev;
        delete target;
        len--;
    }
    int search(T val) const {
        if(!head) return 0;
        Node<T>* temp=head;
        int pos=1;
        while(temp && temp->val!=val) { temp=temp->next; pos++; }
        return (temp?pos:0);
    }
    std::vector<T> values(bool reverse=false) const {
        std::vector<T> vals(len);
        if(reverse) {
            Node<T>* temp=tail;
            for(int i=0;i<len;i++) {
                vals[i]=temp->val;
                temp=temp->prev;
            }
        } else {
            Node<T>* temp=head;
            for(int i=0;i<len;i++) {
                vals[i]=temp->val;
                temp=temp->next;
            }
        }
        return vals;
    }
    void clear() {
        while(head) {
            Node<T>* target=head;
            head=head->next;
            delete target;
        }
        head=tail=nullptr;
        len=0;
    }
    int size() const { return len; }
    bool empty() const { return !len; }

    ~DoublyLinkedList() { clear(); }
};
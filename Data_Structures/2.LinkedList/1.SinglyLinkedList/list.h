#include<vector>
#include<utility>
#include<stdexcept>

template<typename T>
// Node Class
class Node {
public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data=data; // Data in the Node
        next=nullptr; // Points to Next Node of LinkedList
    }
};
template<typename T>
// SinglyLinkedList Class
class SinglyLinkedList {
    Node<T>* head; // Points to Front Node of list
    Node<T>* tail; // Points to Back Node of list
    int len;
    void copy(SinglyLinkedList& current, const SinglyLinkedList& other) {
        Node<T>* copier=other.head;
        while(copier) {
            current.putBack(copier->data);
            copier=copier->next;
        }
    }
public:
    SinglyLinkedList(): head(nullptr), tail(nullptr) ,len(0) {}
    SinglyLinkedList(const SinglyLinkedList& other): head(nullptr), tail(nullptr) ,len(0) {
        copy(*this, other);
    }
    SinglyLinkedList& operator=(const SinglyLinkedList& other) {
        if(this!=&other) {
            clear();
            copy(*this, other);
        }
        return *this;
    }

    void putFront(T data) {
        Node<T>* newNode=new Node<T>(data);
        if(!head) head=tail=newNode;
        else {
            newNode->next=head;
            head=newNode;
        }
        len++;
    }
    void putBack(T data) {
        if(!head) { putFront(data); return; }
        tail->next=new Node<T>(data);
        tail=tail->next;
        len++;
    }
    void remFront() {
        if(!head) throw std::underflow_error("List is empty!\n");
        Node<T>* target=head;
        if(head==tail) head=tail=nullptr;
        else head=head->next;
        delete target;
        len--;
    }
    void remBack() {
        if(!head) throw std::underflow_error("List is empty!\n");
        if(head==tail) { remFront(); return; }
        Node<T>* temp=head;
        while(temp->next!=tail) temp=temp->next;
        tail=temp;
        delete tail->next;
        tail->next=nullptr;
        len--;
    }
    void insertNode(T data,int pos) {
        if(pos<1 || pos>len+1) throw std::out_of_range("Invalid Position!\n");
        if(pos==1) { putFront(data); return; }
        if(pos==len+1) { putBack(data); return; }
        Node<T>* newNode= new Node<T>(data);
        Node<T>* temp=head;
        for(int i=1;i<pos-1;i++) temp=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
        len++;
    }
    void deleteNode(int pos) {
        if(!head) throw std::underflow_error("List is empty!\n");
        if(pos<1 || pos>len) throw std::out_of_range("Invalid Position!\n");
        if(pos==1) { remFront(); return; }
        if(pos==len) { remBack(); return; }
        Node<T>* temp=head;
        for(int i=1;i<pos-1;i++) temp=temp->next;
        Node<T>* target=temp->next;
        temp->next=target->next;
        delete target;
        len--;
    }
    int searchNode(T data) {
        if(!head) return 0;
        int pos=1;
        Node<T>* temp=head;
        while(temp && temp->data!=data) { temp=temp->next; pos++; }
        return (temp?pos:0);
    }
    std::vector<T> values(bool reverse=false) const {
        std::vector<T> vals(len);
        Node<T>* temp=head;
        for(int i=0;i<len;i++) {
            vals[i]=temp->data;
            temp=temp->next;
        }
        if(reverse) {
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
    int size() const { return len; }
    bool empty() const { return !len; }
    void clear() { while(head) remFront(); }

    ~SinglyLinkedList() { clear(); }
};
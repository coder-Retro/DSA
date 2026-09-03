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

// Doubly Linked List Class
template<typename T>
class DoublyLinkedList {
    Node<T>* head;
    Node<T>* tail;
    int len;
public:
    DoublyLinkedList(): head(nullptr), tail(nullptr), len(0) {}
    DoublyLinkedList(const DoublyLinkedList<T>& other): head(nullptr), tail(nullptr), len(0) {
        Node<T>* copier=other.head;
        while(copier) {
            Node<T>* newNode=new Node<T>(copier->val);
            if(!head) head=tail=newNode;
            else {
                newNode->prev=tail;
                tail->next=newNode;
                tail=newNode;
            }
            copier=copier->next;
            len++;
        }
    }

    void insert(T val, int pos) {
        if(pos<1 || pos>len+1) throw std::out_of_range("Invalid Position!\n");
        Node<T>* newNode=new Node<T>(val);
        if(pos==1) {
            if(!head) head=tail=newNode;
            else {
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
            }
        } else if(pos==len+1) {
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        } else {
            Node<T>* temp=head;
            for(int i=1;i<pos-1;i++) temp=temp->next;
            newNode->prev=temp;
            newNode->next=temp->next;
            temp->next->prev=newNode;
            temp->next=newNode;
        }
        len++;
    }
    void remove(int pos) {
        if(!head) throw std::underflow_error("Empty List!\n");
        if(pos<1 || pos>len) throw std::out_of_range("Invalid Position!\n");
        Node<T>* target=head;
        if(pos==1) {
            if(len!=1) {
                head=head->next;
                head->prev=nullptr;
            } else head=tail=nullptr;            
        } else if(pos==len) {
            target=tail;
            tail=tail->prev;
            tail->next=nullptr;
        } else {
            for(int i=1;i<pos;i++) target=target->next;
            target->prev->next=target->next;
            target->next->prev=target->prev;
        }
        delete target;
        len--;
    }
    int search(T val) const {
        if(!head) return 0;
        Node<T>* runner=head;
        int pos=1;
        while(runner && runner->val!=val) {
            runner=runner->next;
            pos++;
        }
        return (runner?pos:0);
    }
    std::vector<T> values(bool reverse=false) const {
        std::vector<T> vals(len);
        if(reverse) {
            Node<T>* runner=tail;
            for(int i=0;i<len;i++) {
                vals[i]=runner->val;
                runner=runner->prev;
            }
        } else {
            Node<T>* runner=head;
            for(int i=0;i<len;i++) {
                vals[i]=runner->val;
                runner=runner->next;
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

    ~DoublyLinkedList() {
        clear();
    }
};
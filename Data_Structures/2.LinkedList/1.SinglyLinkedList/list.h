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
// list Class
class list {
    Node<T>* head; // Points to Front Node of list
    Node<T>* tail; // Points to Back Node of list
public:
    list():head(nullptr),tail(nullptr) {}

    void putFront(T data) {
        Node<T>* newNode=new Node<T>(data); // Creating newNode with data
        if(!head) {
            head=tail=newNode; // Setting head/tail to newNode
            return; // returning to call
        } else {
            newNode->next=head; // Pointing newNode's next to head
            head=newNode; // Updating head to newNode
        }
    }
    void putBack(T data) {
        Node<T>* newNode=new Node<T>(data); // Creating newNode with data
        if(!head) {
            head=tail=newNode; // Setting head/tail to newNode
            return; // returning to call
        } else {
            tail->next=newNode; // Pointing tail's next to newNode
            tail=newNode; // Updating tail to newNode
        }
    }
    void remFront() {
        if(!head) return; // Returning to call
        Node<T>* temp=head; // Creating temp Node<T>* to Front Node
        head=head->next; // Updating head to 2nd Front Node
        delete temp; // Deleting Front Node
    }
    void remBack() {
        if(!head) return;
        if(head==tail) {
            delete head;
            head=tail=nullptr;
            return;
        }
        Node<T>* temp=head; // Creating temp Node<T>* to Front
        while(temp->next!=tail) // While temp!=2nd Back Node
            temp=temp->next; // Updating temp to next Node
        tail=temp; // Setting tail to 2nd Back Node
        delete tail->next; // Deleting Back Node
        tail->next=nullptr; // Setting tail's next to nullptr
    }
    void insertNode(T data,int pos) {
        if(pos<1) return; // If Position is Invalid
        if(pos==1) { putFront(data); return; }
        pos-=2;
        Node<T>* temp=head;
        while(temp && pos--) temp=temp->next;
        if(!temp) return;
        Node<T>* newNode=new Node<T>(data);
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void deleteNode(int pos) {
        if(pos<1 || !head) return;
        if(pos==1) { remFront(); return; }
        pos-=2;
        Node<T>* temp=head;
        while(temp && pos--) temp=temp->next;
        if(!temp || !temp->next) return;
        Node<T>* target=temp->next;
        temp->next=target->next;
        delete target;
    }
    Node<T>* searchNode(T data) {
        Node<T>* temp=head; // Creating temp Node<T>* to Front Node
        while(temp) {
            if(temp->data==data) return temp;
            temp=temp->next;
        }
        return nullptr;
    }
    T front()const {
        if(!head) throw std::runtime_error("List is empty");
        return head->data;
    }
    T back()const {
        if(!head) throw std::runtime_error("List is empty");
        return tail->data;
    }
    bool empty()const { return !head; }
    void clear() { while(head) remFront(); }

    ~list() { clear(); }
};
// ListNode Class
class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int data=0):data(data),next(nullptr){}
};
// Deque Class
class deque{
private:
    ListNode *head,*tail;
public:
    deque(){ head=tail=nullptr; }
    void push_back(int n)
    {
        ListNode* newNode=new ListNode(n);
        if(!head) head=tail=newNode;
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }
    void push_front(int n)
    {
        ListNode* newNode=new ListNode(n);
        if(!head) head=tail=newNode;
        else
        {
            newNode->next=head;
            head=newNode;
        }
    }
    void pop_back()
    {
        if(!head) throw std::runtime_error("Empty");
        else if(head==tail){ tail=nullptr; pop_front(); }
        else
        {
            ListNode* temp=head;
            while(temp->next!=tail) temp=temp->next;
            tail=temp;
            delete tail->next;
            tail->next=nullptr;
        }
    }
    void pop_front()
    {
        if(!head) throw std::runtime_error("Empty");
        else
        {
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }
    }
    int back()
    {
        if(!head) throw std::runtime_error("Empty");
        else return tail->data;
    }
    int front()
    {
        if(!head) throw std::runtime_error("Empty");
        else return head->data;
    }
    bool empty()
    {
        return head==nullptr;
    }
    ~deque(){ while(head) pop_front(); }
};
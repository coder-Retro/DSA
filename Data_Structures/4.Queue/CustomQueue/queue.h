#include<cstddef>
#include<stdexcept>

// Queue Class
template <typename T>
class Queue {
    T* q;
    int front;
    int rear;
    size_t len;
    size_t cap;
    void copy(const Queue& other) {
        q=new T[other.cap];
        cap=other.cap;
        len=other.len;
        for(int i=0;i<(int)len;i++)
            q[i]=other.q[(other.front+i)%other.cap];
        front=0;
        rear=(int)len-1;
    }
public:
    Queue(size_t k=10) {
        if(!k) throw std::invalid_argument("Capacity cannot be 0");
        front=0;
        rear=-1;
        len=0;
        cap=k;
        q=new T[cap];
    }
    Queue(const Queue& other) {
        copy(other);
    }
    Queue& operator=(const Queue& other) {
        if(this!=&other) {
            delete[] q; q=nullptr;
            cap=len=0;
            copy(other);
        }
        return *this;
    }

    bool push(T value) {
        if(full()) return false;
        rear=(rear+1)%cap;
        q[rear]=value;
        len++;
        return true;
    }
    bool pop() {
        if(empty()) return false;
        front=(front+1)%cap;
        len--;
        return true;
    }
    T Front() const {
        if(empty()) throw std::underflow_error("Queue is empty!");
        return q[front];
    }
    T Rear() const {
        if(empty()) throw std::underflow_error("Queue is empty!");
        return q[rear];
    }
    void clear() { front=0,rear=-1,len=0; }
    size_t size() const { return len; }
    bool empty() const { return !len; }
    bool full() const { return len==cap; }
    
    ~Queue() { delete[] q; }
};
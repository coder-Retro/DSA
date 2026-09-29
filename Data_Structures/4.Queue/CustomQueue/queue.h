#include<stdexcept>

template <typename T>
class Queue {
    T* q;
    int front;
    int rear;
    int size;
    int cap;
public:
    Queue(int k) {
        front=0;
        rear=-1;
        size=0;
        cap=k;
        q=new T[cap];
    }
    bool push(T value) {
        if(full()) return false;
        rear=(rear+1)%cap;
        q[rear]=value;
        size++;
        return true;
    }
    bool pop() {
        if(empty()) return false;
        front=(front+1)%cap;
        size--;
        return true;
    }
    T Front() { return empty()?-1:q[front]; }
    T Rear() { return empty()?-1:q[rear]; }
    bool empty() { return !size; }
    bool full() { return size==cap; }
    
    ~Queue() { delete[] q; }
};
#include<stdexcept>

template <typename T>
// Stack Class
class Stack {
private:
    T* ptr;
    int cap;
    int topVal;
    void copy(const Stack& other) {
        topVal=other.topVal;
        cap=other.cap;
        ptr=new T[cap];
        for(int i=0;i<other.size();i++)
            ptr[i]=other.ptr[i];
    }
public:
    Stack(int size=10) {
        if(size<0) throw std::range_error("Stack size cannot be negative!");
        topVal=-1;
        cap=size?size:10;
        ptr=new T[cap];
    }
    Stack(const Stack& other) {
        copy(other);
    }
    Stack& operator=(const Stack& other) {
        if(this!=&other) {
            T* newPtr = new (std::nothrow) T[other.cap];
            if(!newPtr) throw std::runtime_error("Memory allocation failed!");
            for(int i=0;i<other.size();i++)
                newPtr[i]=other.ptr[i];
            delete[] ptr;
            ptr = newPtr;
            cap = other.cap;
            topVal = other.topVal;
        }
        return *this;
    }

    void push(T& n) { 
        if(full()) throw std::overflow_error("Stack overflow!");
        ptr[++topVal]=n; }
    T pop() {
        if(empty()) throw std::underflow_error("Stack is empty!");
        return ptr[topVal--];
    }
    T top() {
        if(empty()) throw std::underflow_error("Stack is empty!");
        return ptr[topVal];
    }
    void clear() { while(!empty()) pop(); }
    int size() const { return topVal+1; }
    bool full() const { return topVal+1==cap; }
    bool empty() const { return topVal==-1; }

    ~Stack() { delete[] ptr; }
};
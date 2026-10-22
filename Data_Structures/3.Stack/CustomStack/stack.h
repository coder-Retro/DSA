#include<cstddef>
#include<stdexcept>

// Stack Class
template <typename T>
class Stack {
private:
    T* ptr;
    size_t cap;
    int topVal;
    void copy(const Stack& other) {
        ptr=new T[other.cap];
        topVal=other.topVal;
        cap=other.cap;
        for(int i=0;i<other.size();i++)
            ptr[i]=other.ptr[i];
    }
public:
    Stack(int k=10) {
        if(k<=0) throw std::invalid_argument("Capacity cannot be 0 or negative!");
        topVal=-1;
        cap=(size_t)k;
        ptr=new T[cap];
    }
    Stack(const Stack& other) {
        copy(other);
    }
    Stack& operator=(const Stack& other) {
        if(this!=&other) {
            delete[] ptr; ptr=nullptr;
            cap=0,topVal=-1;
            copy(other);
        }
        return *this;
    }

    bool push(T n) { 
        if(full()) return false;
        ptr[++topVal]=n; 
        return true;
    }
    bool pop() {
        if(empty()) return false;
        topVal--;
        return true;
    }
    T top() const {
        if(empty()) throw std::underflow_error("Stack is empty!");
        return ptr[topVal];
    }
    void clear() { topVal=-1; }
    int size() const { return topVal+1; }
    bool full() const { return (size_t)(topVal+1)==cap; }
    bool empty() const { return topVal==-1; }

    ~Stack() { delete[] ptr; }
};
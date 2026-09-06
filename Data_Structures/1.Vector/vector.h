#include<stdexcept>

template<typename T>
// Vector Class
class Vector {
private:
    T* ptr;
    int cap;
    int len;
public:
    Vector(int cap=0):cap(cap),len(0) {
        if(cap<0) throw std::invalid_argument("Negative Capacity Passed!\n");
        ptr=(this->cap)?new T[this->cap]:nullptr;
    }
    Vector(const Vector& v):cap(v.cap),len(v.len) {
        ptr=new T[cap];
        for(int i=0;i<len;i++)
            ptr[i]=v.ptr[i];
    }
    Vector& operator=(const Vector& v) {
        if(this!=&v) {
            T* newPtr=new T[v.cap];
            for(int i=0;i<v.len;i++)
                newPtr[i]=v.ptr[i];
            delete[] ptr;
            ptr=newPtr;
            cap=v.cap;
            len=v.len;
        }
        return *this;
    }
    void resize() {
        cap=(cap)?cap*2:1;
        T* newPtr=new T[cap];
        for(int i=0;i<len;i++) newPtr[i]=ptr[i];
        delete[] ptr;
        ptr=newPtr;
    }
    void push_back(T val) {
        if(len==cap) resize();
        ptr[len++]=val;
    }
    void pop_back() { if(len) len--; }
    T& operator[](int index) {
        if(index<0||index>=len)
            throw std::runtime_error("Invalid Index!");
        return ptr[index];
    }
    T* begin()const { return ptr; }
    T* end()const { return ptr+len; }
    int size()const { return len; }
    int capacity()const { return cap; }
    bool empty()const { return !len; }

    ~Vector() { delete[] ptr; }
};
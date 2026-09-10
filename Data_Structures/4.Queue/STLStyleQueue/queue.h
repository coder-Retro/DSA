#include<list>
#include<stdexcept>

template <typename T>
// Queue Class
class Queue {
private:
    std::list<T> l;
public:
    void push(T val) { l.push_back(val); }
    void pop() {
        if(l.empty()) throw std::underflow_error("Queue is empty!\n");
        l.pop_front();
    }
    T front() { 
        if(l.empty()) throw std::underflow_error("Queue is empty!\n");
        return l.front();
    }
    int size() const { return l.size(); }
    bool empty() const { return l.empty(); }
};
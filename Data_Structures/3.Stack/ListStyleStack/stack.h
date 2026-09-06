#include<list>
#include<stdexcept>

template <typename T>
class Stack {
private:
    std::list<T> l;
public:
    void push(T n) { l.push_front(n); }
    void pop() {
        if(l.empty()) throw std::underflow_error("Stack Is Empty!");
        l.pop_front();
    }
    T top() {
        if(l.empty()) throw std::underflow_error("Stack Is Empty!");
        return l.front();
    }
    int size() const { return l.size(); }
    bool empty() const { return l.empty(); }
};
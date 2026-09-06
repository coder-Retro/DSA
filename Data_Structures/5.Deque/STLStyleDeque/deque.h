#include<list>
#include<stdexcept>

template <typename T>
// Deque Class
class Deque {
private:
    std::list<T> l;
public:
    void push_back(T n) { l.push_back(n); }
    void push_front(T n) { l.push_front(n); }
    void pop_front() {
        if(l.empty()) throw std::underflow_error("Deque is empty!\n");
        l.pop_front();
    }
    void pop_back() {
        if(l.empty()) throw std::underflow_error("Deque is empty!\n");
        l.pop_back();
    }
    T front() {
        if(l.empty()) throw std::underflow_error("Deque is empty!\n");
        return l.front();
    }
    T back() {
        if(l.empty()) throw std::underflow_error("Deque is empty!\n");
        return l.back();
    }
    int size() const { return l.size(); }
    bool empty() const { return l.empty(); }
};
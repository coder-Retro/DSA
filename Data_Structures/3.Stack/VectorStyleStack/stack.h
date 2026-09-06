#include<vector>
#include<stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> v;
public:
    void push(T n) { v.push_back(n); }
    void pop() {
        if(v.empty()) throw std::underflow_error("Stack Is Empty!");
        v.pop_back();
    }
    T top() {
        if(v.empty()) throw std::underflow_error("Stack Is Empty!");
        return v.back();
    }
    int size() const { return v.size(); }
    bool empty() const { return v.empty(); }
};
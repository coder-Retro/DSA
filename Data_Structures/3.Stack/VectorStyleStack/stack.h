#include<vector>
#include<stdexcept>

template <typename T>
// Stack Class
class Stack {
private:
    std::vector<T> v;
public:
    void push(T n) { v.push_back(n); }
    T pop() {
        if(v.empty()) throw std::underflow_error("Stack Is Empty!\n");
        T val=v.back();
        v.pop_back();
        return val;
    }
    T top() {
        if(v.empty()) throw std::underflow_error("Stack Is Empty!\n");
        return v.back();
    }
    int size() const { return v.size(); }
    bool empty() const { return v.empty(); }
};
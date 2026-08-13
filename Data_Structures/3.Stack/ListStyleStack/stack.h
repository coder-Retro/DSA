#include<list>
class stack
{
private:
    std::list<int> l;
public:
    void push(int n){ l.push_front(n); }
    void pop(){
        if(l.empty()) throw std::runtime_error("Stack Is Empty!");
        l.pop_front();
    }
    int top(){
        if(l.empty()) throw std::runtime_error("Stack Is Empty!");
        return l.front();
    }
    bool empty(){ return l.empty(); }
};
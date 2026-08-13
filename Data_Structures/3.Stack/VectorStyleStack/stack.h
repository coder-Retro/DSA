#include<vector>
class stack
{
private:
    std::vector<int> v;
public:
    void push(int n){ v.push_back(n); }
    void pop(){
        if(v.empty()) throw std::runtime_error("Stack Is Empty!");
        v.pop_back();
    }
    int top(){
        if(v.empty()) throw std::runtime_error("Stack Is Empty!");
        return v.back();
    }
    bool empty(){ return v.empty(); }
};
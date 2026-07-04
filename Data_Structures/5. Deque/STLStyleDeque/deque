#include<list>
class deque{
private:
    std::list<int> l;
public:
    void push_back(int n)
    {
        l.push_back(n);
    }
    void push_front(int n)
    {
        l.push_front(n);
    }
    void pop_back()
    {
        if(l.empty()) throw std::runtime_error("Empty");
        else l.pop_back();
    }
    void pop_front()
    {
        if(l.empty()) throw std::runtime_error("Empty");
        else l.pop_front();
    }
    int back()
    {
        if(l.empty()) throw std::runtime_error("Empty");
        else return l.back();
    }
    int front()
    {
        if(l.empty()) throw std::runtime_error("Empty");
        else return l.front();
    }
    bool empty()
    {
        return l.empty();
    }
};
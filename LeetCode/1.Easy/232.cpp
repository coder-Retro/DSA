#include<iostream>
#include<stack>
using namespace std;

/*
Constructor:
Approach: None
TC: O(1)
SC: O(1)

push:
Approach: Stack Loading
TC: O(1)
SC: O(1)

pop:
Approach: Stack Shifting
TC: O(1)
SC: O(1)

peek:
Approach: Retrieve Outstack Element
TC: O(1)
SC: O(1)

empty:
Approach: Check empty stacks
TC: O(1)
SC: O(1)
*/

class MyQueue {
    stack<int> in,out;
    void move() {
        if(!out.empty()) return;
        while(!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
public:
    MyQueue() {}
    
    void push(int x) { in.push(x); }
    
    int pop() {
        move();
        int val=out.top();
        out.pop();
        return val;
    }
    
    int peek() {
        move();
        return out.top();
    }
    bool empty() { return in.empty()&&out.empty(); }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    cout<<obj->peek()<<'\n';
    cout<<obj->pop()<<'\n';
    cout<<obj->empty();
    delete obj;
    return 0;
}
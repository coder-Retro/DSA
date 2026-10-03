#include<iostream>
#include<queue>
using namespace std;

/*
Constructor
Approach: None
TC: O(1)
SC: O(1)

push:
Approach: Queue Rotation
TC: O(n)
SC: O(1)

pop:
Approach: Queue Front Deletion
TC: O(1)
SC: O(1)

top:
Approach: Queue Front Retrieval
TC: O(1)
SC: O(1)

empty:
Approach: Empty Queue check
TC: O(1)
SC: O(1)
*/

class MyStack {
    queue<int> stk,saver;
public:
    MyStack() {}
    
    void push(int x) {
        stk.push(x);
        while(stk.size()>1) {
            saver.push(stk.front());
            stk.pop();
        }
        while(saver.size()) {
            stk.push(saver.front());
            saver.pop();
        }
    }
    
    int pop() {
        int val=stk.front();
        stk.pop();
        return val;
    }
    
    int top() { return stk.front(); }
    
    bool empty() { return stk.empty(); }
};

int main() {
   MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout<<obj->top()<<'\n';
    cout<<obj->pop()<<'\n';
    cout<<(obj->empty()?"true":"false")<<'\n';
    delete obj;
    return 0;
}
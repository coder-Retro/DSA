#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Constructor:
Approach: None
TC: O(1)
SC: O(1)

push:
Approach: Min Tracking Insertion
TC: O(1)
SC: O(1)

pop:
Approach: Stack Pop
TC: O(1)
SC: O(1)

top:
Approach: Stack Peek
TC: O(1)
SC: O(1)

getMin:
Approach: PreComputed Min Retrieval
TC: O(1)
SC: O(1)
*/

class MinStack {
    vector<pair<int,int>> st;
public:
    MinStack() {}
    void push(int value) {
        int currMin=st.empty()?value:min(value,st.back().second);
        st.push_back({value,currMin});
    }
    void pop() {
        st.pop_back();
    }
    int top() {
        return st.back().first;
    }
    int getMin() {
        return st.back().second;
    }
};

int main() {
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout<<obj.getMin()<<'\n';
    obj.pop();
    cout<<obj.top()<<'\n';
    cout<<obj.getMin()<<'\n';
    return 0;
}
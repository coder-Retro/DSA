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
private:
    vector<pair<int,int>> st;
public:
    MinStack() {}

    void push(int value) {
        int currMin=st.empty()?value:min(value,st.back().second);
        st.push_back({value,currMin});
    }

    void pop() { st.pop_back(); }

    int top() { return st.back().first; }

    int getMin() { return st.back().second; }
};
int main() {
    MinStack mS;
    mS.push(-2);
    mS.push(0);
    mS.push(-3);
    cout<<mS.getMin()<<'\n';
    mS.pop();
    cout<<mS.top()<<'\n';
    cout<<mS.getMin()<<'\n';
    return 0;
}
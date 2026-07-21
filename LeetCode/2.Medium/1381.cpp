#include<iostream>
#include<vector>
using namespace std;

/*
Constructor:
Approach: Vector Resizing
TC: O(1)
SC: O(maxSize), maxSize = capaity of vector

push:
Approach: Stack Winding
TC: O(1)
SC: O(1)

pop:
Approach: Stack Unwinding
TC: O(1)
SC: O(1)

increment:
Approach: Linear Increment
TC: O(min(k,st.size()))
SC: O(1)
*/

class CustomStack {
    vector<int> st;
    int mS;
public:
    CustomStack(int maxSize): mS(maxSize) { st.reserve(mS); }
    
    void push(int x) { if((int)st.size()<mS) st.push_back(x); }
    
    int pop() {
        if(st.empty()) return -1;
        int ans=st.back();
        st.pop_back();
        return ans;    
    }
    
    void increment(int k, int val) {
        for(int& i:st)
            if(!k--) break;
            else     i+=val;
    }
};
int main() {
    int maxSize=3;
    CustomStack obj(maxSize);
    obj.push(1);
    obj.push(2);
    cout<<obj.pop()<<'\n';
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.increment(5,100);
    obj.increment(2,100);
    cout<<obj.pop()<<'\n';
    cout<<obj.pop()<<'\n';
    cout<<obj.pop()<<'\n';
    cout<<obj.pop()<<'\n';
    return 0;
}
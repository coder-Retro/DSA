#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    void add(stack<int>& st) {
        int top=st.top(); st.pop();
        int newVal=top+st.top();
        st.push(top); st.push(newVal);
    }
    void dub(stack<int>& st) {
        st.push(st.top()*2);
    }
public:
    int calPoints(vector<string>& operations) {
        int sum=0;
        stack<int> st;
        for(string op:operations) {
            if(op=="+")      add(st);
            else if(op=="D") dub(st);
            else if(op=="C") st.pop();
            else             st.push(stoi(op));
        }
        while(!st.empty()) { sum+=st.top(); st.pop(); }
        return sum;
    }
};

int main() {
    Solution obj;
    vector<string> ops={"5","2","C","D","+"};
    cout<<obj.calPoints(ops);
    return 0;
}
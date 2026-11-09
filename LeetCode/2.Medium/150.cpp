#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

/*
Approach: Postfix Evaluation / Stack
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token:tokens) {
            if(token!="+"&&token!="-"&&token!="*"&&token!="/")
                st.push(stoi(token));
            else {
                int op2=st.top(); st.pop();
                int op1=st.top(); st.pop();
                if(token=="+")      st.push(op1+op2);
                else if(token=="-") st.push(op1-op2);
                else if(token=="*") st.push(op1*op2);
                else                st.push(op1/op2);
            }
        }
        return st.top();
    }
};

int main() {
    Solution obj;
    vector<vector<string>> tests = {
        {"2","1","+","3","*"},
        {"4","13","5","/","+"},
        {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}
    };
    for(auto& test:tests) cout<<obj.evalRPN(test)<<'\n';
    return 0;
}
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

/*
Approach: Stack Reversal
TC: O(n²)
SC: O(n)
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");
        for(char ch:s) {
            if(ch=='(') st.push("");
            else if(ch==')') {
                string curr=st.top();
                st.pop();
                reverse(curr.begin(),curr.end());
                st.top()+=curr;
            }
            else st.top()+=ch;
        }
        return st.top();
    }
};

int main() {
    Solution obj;
    string strs[]={
        "(abcd)",
        "(u(love)i)",
        "(ed(et(oc))el)"
    };
    for(string& str:strs) cout<<obj.reverseParentheses(str)<<'\n';
    return 0;
}
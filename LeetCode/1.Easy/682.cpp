#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum=0;
        stack<int> st;
        for(string op:operations) {
            if(op=="+") {
                int save=st.top(); st.pop();
                int sum=save+st.top();
                st.push(save); st.push(sum);
            }
            else if(op=="D") st.push(st.top()*2);
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
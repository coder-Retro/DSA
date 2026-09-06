#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
Approach: Stack Winding / Max Tracking
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> lastOpen;
        lastOpen.push(-1); // Adding empty stack guard
        int maxL=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='(') lastOpen.push(i); // Opening detected
            else { 
                lastOpen.pop();
                if(!lastOpen.empty()) maxL=max(maxL,i-lastOpen.top());
                else lastOpen.push(i); // Restoring empty stack guard
                // i-lastOpen.top() is the currently longest Valid range
            }
        return maxL;
    }
};

int main() {
    Solution obj;
    string s=")()())";
    cout<<obj.longestValidParentheses(s);
    return 0;
}
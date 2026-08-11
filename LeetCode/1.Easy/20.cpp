#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
Approach: Stack Pass
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        char target;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                open.push(s[i]);
            else {
                if(open.empty()) return false;
                target=open.top();
                if(s[i]==')'&&target=='(') open.pop();
                else if(s[i]=='}'&&target=='{') open.pop();
                else if(s[i]==']'&&target=='[') open.pop();
                else return false;
            }
        }
        return open.empty();
    }
};

int main() {
    Solution obj;
    string t[8]={"()","()[]{}","(]","([])","([)]","[","((","(])"};
    for(int i=0;i<8;i++)
        (obj.isValid(t[i]))?cout<<"true\n":cout<<"false\n";
    return 0;
}
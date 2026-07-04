#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s,string t) {
        if(!s.length()) return true;
        if(s.length()>t.length()) return false;
        int i=0,j=0;
        while(i<s.length() && j<t.length()) if(t[j++]==s[i]) i++;
        return i==s.length();
    }
};
int main() {
    Solution s;
    string str1="abc";
    string str2="ahbgdc";
    if(s.isSubsequence(str1,str2))
        cout<<str1<<" is subsequence of "<<str2;
    else
        cout<<str1<<" is not subsequence of "<<str2;
    return 0;
}
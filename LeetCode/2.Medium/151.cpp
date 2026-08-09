#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
Approach: Stack
TC: O(n²)
SC: O(n)
*/

class Solution {
    void trim(string& s) {
        if(s.empty()) return;
        int i=0,j=s.size()-1;
        while(i<j && s[i] == ' ') i++;
        while(i<j && s[j] == ' ') j--;
        if(s[i] == ' ' && s[j] == ' ') { s = ""; return; }
        s = s.substr(i, j-i+1);
    }
    string firstWord(string& s) {
        if(!s.size()) return "";
        int i=0,j=0;
        while(j<s.size() && s[j]!=' ') j++;
        string first;
        if(j == s.size()) {
            first = s;
            s = "";
        } else {
            first = s.substr(i,j-i);
            s = s.substr(j+1,s.size()-j+1);
        }
        return first;
    }
public:
    string reverseWords(string str) {
        string ans ="";
        while(str.size()) {
            trim(str);
            ans = firstWord(str) + " " + ans;
        }
        trim(ans);
        return ans;
    }
};
int main() {
    Solution obj;
    string str = "a good   example";
    cout << obj.reverseWords(str);
    return 0;
}
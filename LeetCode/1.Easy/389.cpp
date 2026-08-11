#include<iostream>
#include<string>
using namespace std;

/*
Approach: Bit Manipulation
TC: O(m+n), m and n are lengths of strings
SC: O(1)
*/

class Solution {
public:
    char findTheDifference(string s,string t) {
        int ans=0;
        for(char c:s) ans^=c;
        for(char c:t) ans^=c;
        return ans;
    }
};

int main() {
    Solution obj;
    string str1="abcd";
    string str2="abcde";
    cout<<obj.findTheDifference(str1,str2);
    return 0;
}
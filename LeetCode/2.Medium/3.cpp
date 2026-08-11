#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
Approach: Max Tracking
TC: O(n²)
SC: O(m), m = length of longest substring
*/

class Solution {
public:
    int LengthOfLongestSubstring(string s) {
        string curr="";
        int maxL=0;
        for(char c:s) {
            if(curr.find(c)!=string::npos)
                curr=curr.substr(curr.find(c)+1);
            curr+=c;
            maxL=max(maxL,(int)curr.length());
        }
        return maxL;
    }
};

int main() {
    Solution obj;
    string str="abcabcbb";
    cout<<obj.LengthOfLongestSubstring(str);
    return 0;
}
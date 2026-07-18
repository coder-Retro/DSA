#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
Approach: Sorting / String Matching
TC: O(m * n log n), m = average length of strings
SC: O(m + log n), m = average length of strings
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(),strs.end());
        const string& s1=strs[0];
        const string& s2=strs.back();
        int minLen=min(s1.size(),s2.size());
        for(int i=0;i<minLen;i++)
            if(s1[i]==s2[i]) ans+=s1[i];
            else             break;
        return ans;
    }
};
int main() {
    Solution obj;
    vector<string> strs={"flower","flow","flight"};
    cout<<obj.longestCommonPrefix(strs);
    return 0;
}
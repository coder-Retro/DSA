#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/*
Approach: Hashing
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;
        for(char c:s) freq[c]++;
        for(int i=0;i<s.size();i++) {
            auto it=freq.find(s[i]);
            if(it->second==1) return i;
        }
        return -1;
    }
};

int main() {
    Solution obj;
    string s="leetcode";
    cout<<obj.firstUniqChar(s);
    return 0;
}
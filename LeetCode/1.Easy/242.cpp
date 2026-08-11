#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
Approach: Hashing
TC: O(m+n), m and n are lengths of strings
SC: O(1)
*/

class Solution {
public:
    bool isAnagram(string s,string t){
        if(s.length() != t.length()) return false;
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        for(char c:t) freq[c-'a']--;
        for(int i:freq) if(i) return false;
        return true;
    }
};

int main() {
    Solution obj;
    string s="anagram";
    string t="nagaram";
    if(obj.isAnagram(s,t)) cout<<"Is Anagram";
    else                   cout<<"Is Not Anagram";
    return 0;
}
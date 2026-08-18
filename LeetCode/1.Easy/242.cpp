#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/*
Approach: Hashing
TC: O(m+n), m and n are lengths of strings
SC: O(m+n)
*/

class Solution {
public:
    bool isAnagram(string s,string t){
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> freq;
        for(char c:s) freq[c-'a']++;
        for(char c:t) freq[c-'a']--;
        for(auto it:freq) if(it.second) return false;
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
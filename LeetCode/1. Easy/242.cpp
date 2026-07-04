#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s,string t){
        if(s.length() != t.length()) return false;
        int i,freq[26]={0};
        for(char c:s) freq[c-97]++;
        for(char c:t) freq[c-97]--;
        for(int i=0;i<26;i++) if(freq[i]) return false;
        return true;
    }
};
int main()
{
    Solution sol;
    string s="anagram";
    string t="nagaram";
    if(sol.isAnagram(s,t)) cout<<"Is Anagram";
    else              cout<<"Is Not Anagram";
    return 0;
}
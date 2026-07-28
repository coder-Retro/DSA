#include<iostream>
#include<string>
using namespace std;

/*
Approach: Counting Sort / Two Pointers
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        unsigned int freq[26]={0};
        for(int i=0;i<n/2;i++) freq[s[i]-'a']++;
        for(int i=0,j=n-1,k=0;k<26;k++)
            while(i<j && freq[k]--) {
                s[i++]='a'+k;
                s[j--]='a'+k;
            }
        return s;
    }
};
int main() {
    Solution obj;
    string s="babab";
    cout<<obj.smallestPalindrome(s);
    return 0;
}
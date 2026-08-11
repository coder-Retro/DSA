#include<iostream>
#include<string>
#include<utility>
using namespace std;

/*
Approach: Hashing / Two Pointer
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    string reverseVowels(string s) {
        bool isVowel[256]={false};
        string v="AEIOUaeiou";
        for(char c:v) isVowel[c]=true;
        int i=0,j=s.length()-1;
        while(i<j) {
            // Finding Left Vowel
            while(i<j && !isVowel[(unsigned char)s[i]]) i++;
            // Finding Right Vowel
            while(i<j && !isVowel[(unsigned char)s[j]]) j--;
            if(i<j) {
                // Reversing Vowels
                swap(s[i],s[j]);
                i++,j--;
            }
        }
        return s;
    }
};

int main() {
    Solution obj;
    string str="IceCreAm";
    string rev=obj.reverseVowels(str);
    cout<<rev;
    return 0;
}
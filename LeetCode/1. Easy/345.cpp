#include<iostream>
#include<string>
#include<utility>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        string v="AEIOUaeiou";
        int i=0,j=s.length()-1;
        while(i<j) {
            // Finding Left Vowel
            while(i<j && v.find(s[i])==string::npos) i++;
            // Finding Right Vowel
            while(i<j && v.find(s[j])==string::npos) j--;
            // Reversing Vowels
            swap(s[i],s[j]);
            // Updating Iterators
            i++,j--;
        }
        return s;
    }
};
int main() {
    Solution s;
    string str="IceCreAm";
    string rev=s.reverseVowels(str);
    cout<<rev;
    return 0;
}
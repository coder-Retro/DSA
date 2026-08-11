#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Hashing / Frequency Counting
TC: O(n), n = size of magazine string
SC: O(1)
*/

class Solution {
public:
    bool canConstruct(string ransomNote,string magazine) {
        vector<int> freq(26, 0);
        for(char c:magazine) freq[c-'a']++;
        for(char c:ransomNote) {
            freq[c-'a']--;
            if(freq[c-'a']<0) return false;
        }
        return true;
    }
};

int main() {
    Solution obj;
    string ransomNote="fihjjjjei";
    string magazine="hjibagacbhadfaefdjaeaebgi";
    cout<<(obj.canConstruct(ransomNote,magazine)?"true":"false");
    return 0;
}
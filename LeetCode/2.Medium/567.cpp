#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Approach: Frequency Counting / Sliding Window
TC: O(m), m = size of s2
SC: O(1)
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int> freq(26, 0);
        for(char c:s1) freq[c - 'a']++;
        vector<int> wind(26, 0);
        for(int i = 0; i < n; i++) wind[s2[i] - 'a']++;
        for(int i = 0; i + n < m; i++) {
            if(wind == freq) return true;
            wind[s2[i] - 'a']--;
            wind[s2[i+n] - 'a']++;
        }
        return wind == freq;
    }
};
int main() {
    Solution obj;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << (obj.checkInclusion(s1, s2)?"true":"false");
    return 0;
}
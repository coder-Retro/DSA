#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Sorting / Greedy
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int minimumPushes(string word) {
        int totalPushes=0;
        vector<int> freq(26,0);
        for(char c:word) freq[c-'a']++;
        sort(freq.rbegin(),freq.rend());
        for(int i=0;i<26;i++) {
            if(!freq[i]) break;
            if(i<8)       totalPushes+=(freq[i]);
            else if(i<16) totalPushes+=(freq[i]*2);
            else if(i<24) totalPushes+=(freq[i]*3);
            else          totalPushes+=(freq[i]*4);
        }
        return totalPushes;
    }
};
int main() {
    Solution obj;
    string word="aabbccddeeffgghhiiiiii";
    cout<<obj.minimumPushes(word);
    return 0;
}
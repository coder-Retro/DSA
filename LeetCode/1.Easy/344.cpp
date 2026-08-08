#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: In-Place Two Pointer Reversal
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        while(i<j) swap(s[i++],s[j--]);
    }
};
int main() {
    Solution s;
    vector<char> str={'h','e','l','l','o'};
    s.reverseString(str);
    for(char c:str) cout<<c;
    return 0;
}
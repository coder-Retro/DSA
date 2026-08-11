#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: Two Pointers
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
    Solution obj;
    vector<char> str={'h','e','l','l','o'};
    obj.reverseString(str);
    for(char c:str) cout<<c;
    return 0;
}
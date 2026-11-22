#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Approach: Simulation / Linear Pass
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    bool checkString(string s) {
        bool seen_b=false;
        for(char ch:s) {
            if(ch=='b') seen_b=true;
            else if(seen_b) return false;
        }
        return true;
    }
};

int main() {
    Solution obj;
    vector<string> strs={"aaabbb","abab","bbb"};
    for(string str:strs) cout<<(obj.checkString(str)?"true":"false")<<'\n';
    return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
Approach: Greedy / Range Tracking
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen=0,maxOpen=0; // Range of Possible unmatched Openings '('
        for(char ch:s) {
            switch(ch) {
                case '(': minOpen++; maxOpen++; break; // Opening, Move Forward
                case ')': minOpen--; maxOpen--; break; // Closing, Move Backward
                default:  minOpen--; maxOpen++; // Asterisk, Expanding Range
            }
            if(maxOpen<0) return false; // Range Ending Underflow, Invalid String
            minOpen=max(minOpen,0); // Range Starting Underflow, Resetting Starting
        }
        return !minOpen; // All Opens Closed
    }
};

int main() {
    Solution obj;
    string s[]={
        "()",
        "(*)",
        "(*))",
        "("
    };
    for(int i=0;i<sizeof(s)/sizeof(s[0]);i++)
        cout<<(obj.checkValidString(s[i])?"true":"false")<<'\n';
    return 0;
}
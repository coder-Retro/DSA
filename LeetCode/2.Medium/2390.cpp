#include<iostream>
using namespace std;

/*
Approach: Stack / Simulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(char ch:s)
            if(ch!='*') ans.push_back(ch);
            else        ans.pop_back();
        return ans;
    }
};

int main() {
    Solution obj;
    string s="leet**cod*e";
    cout<<obj.removeStars(s);
    return 0;
}
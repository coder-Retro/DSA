#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Approach: Greedy / Simulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,need=0;
        for(char ch:s) {
            if(ch=='(') open++;
            else if(open) open--;
            else need++;
        }
        return open+need;
    }
};

int main() {
    Solution obj;
    vector<string> tests={
        "())",
        "((("
    };
    for(string s:tests) cout<<obj.minAddToMakeValid(s)<<'\n';
    return 0;
}
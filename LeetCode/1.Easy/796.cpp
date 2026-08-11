#include<iostream>
#include<string>
using namespace std;

/*
Approach: String Matching
TC: O(n²)
SC: O(n)
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        s+=s;
        return (s.find(goal)!=string::npos);
    }
};

int main() {
    Solution obj;
    string s="abcde";
    string goal="cdeab";
    cout<<(obj.rotateString(s,goal)?"true":"false");
    return 0;
}
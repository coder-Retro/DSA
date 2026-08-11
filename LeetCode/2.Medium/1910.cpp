#include<iostream>
#include<string>
using namespace std;

/*
Approach: Simulation / String Matching
TC: O(n²)
SC: O(1)
*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int start=s.find(part);
        while(start!=string::npos) {
            s.erase(start,part.size());
            start=s.find(part);
        }
        return s;
    }
};

int main() {
    Solution obj;
    string s="axxxxyyyyb";
    string part="xy";
    cout<<obj.removeOccurrences(s,part);
    return 0;
}
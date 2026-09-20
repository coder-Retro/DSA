#include<iostream>
#include<string>
using namespace std;

/*
Approach: Simulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++)
            sum+=(i+1)*('z'+1-s[i]);
        return sum;
    }
};

int main() {
    Solution obj;
    string s="abc";
    cout<<obj.reverseDegree(s);
    return 0;
}
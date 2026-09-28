#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
Approach: Simulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int maxDepth(string s) {
        int open=0,maxOpen=0;
        for(char ch:s) {
            if(ch=='(') open++;
            if(ch==')') open--;
            maxOpen=max(maxOpen,open);
        }
        return maxOpen;
    }
};

int main() {
    Solution obj;
    string s="(1+(2*3)+((8)/4))+1";
    cout<<obj.maxDepth(s)<<'\n';
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Approach: Simulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        for(string log:logs) {
            if(log=="./")       continue;
            else if(log=="../") { if(depth) depth--; }
            else                depth++;
        }
        return depth;
    }
};

int main() {
    Solution obj;
    vector<string> logs={"d1/","d2/","../","d21/","./"};
    cout<<obj.minOperations(logs);
    return 0;
}
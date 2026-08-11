#include<iostream>
using namespace std;

/*
Approach: Bit Manipulation
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int numberOfSteps(int num) {
        int steps=0;
        while(num) {
            if(num&1) num&=(~1); // Switching Off LSB
            else      num>>=1;   // Division By 2
            steps++;
        }
        return steps;
    }
};

int main() {
    Solution obj;
    int num=14;
    cout<<obj.numberOfSteps(num);
    return 0;
}
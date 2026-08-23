#include<iostream>
using namespace std;

/*
Problem Statement:
You are required to write a function which will take int steps
in the argument, this is the number of steps on a stair case.
At each step you can either climb one or two steps upwards. Your
function should return the number of distinct way in which you
can reach the top of staircase

Constraints:
1. Your approach should be DP based.
2. Your solution should be O(n) in time.
3. Your solution should be O(1) in space.
*/

class DynamicProgramming {
public:
    int climbStairs(int n) {
        // Your Code Here
    }
};

int main() {
    DynamicProgramming obj;
    int steps=11;
    cout<<obj.climbStairs(steps);
    return 0;
}
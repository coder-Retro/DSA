#include<iostream>
using namespace std;

/*
Approach: Dynamic Programming
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        int first=1;
        int second=1;
        int third;
        for(int i=2;i<=n;i++) {
            third=first+second;
            first=second;
            second=third;
        }
        return third;
    }
};

int main() {
    Solution obj;
    int steps=11;
    cout<<obj.climbStairs(steps);
    return 0;
}
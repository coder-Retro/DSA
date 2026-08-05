#include<iostream>
using namespace std;

/*
Approach: Space Optimized Dynamic Programming
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int tribonacci(int n) {
        if(n<2) return n;
        int one=0,two=1,three=1;
        for(int i=3;i<=n;i++) {
            int four=one+two+three;
            one=two;
            two=three;
            three=four;
        }
        return three;
    }
};
int main() {
    Solution obj;
    int n=25;
    cout<<obj.tribonacci(n);
    return 0;
}
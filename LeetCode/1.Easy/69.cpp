#include<iostream>
using namespace std;

/*
Approach: Linear Search / Newton Formula
TC: O(sqrt(x))
SC: O(1)
*/

class Solution {
public:
    int mySqrt(int x) {
        double i;
        for(i=1;i*i<x;i++);
        return (int)(i+((x-i*i)/(2*i)));
    }
};
int main() {
    Solution obj;
    int x=10;
    cout<<obj.mySqrt(x);
    return 0;
}
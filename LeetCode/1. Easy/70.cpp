#include<iostream>
using namespace std;
class Solution
{
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        int first=1;
        int second=1;
        int third;
        for(int i=2;i<=n;i++)
        {
            third=first+second;
            first=second;
            second=third;
        }
        return third;
    }
};
int main()
{
    Solution s;
    int steps=11;
    cout<<s.climbStairs(steps);
    return 0;
}
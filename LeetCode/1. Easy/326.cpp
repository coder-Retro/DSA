#include<iostream>
using namespace std;
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        long pow=1;
        while(pow*3<=n) pow*=3;
        if(pow==n) return true;
        return false;
    }
};
int main()
{
    Solution s;
    int n=1;
    (s.isPowerOfThree(n))?cout<<"true":cout<<"false";
    return 0;
}
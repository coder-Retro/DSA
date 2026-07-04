#include<iostream>
using namespace std;
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        long pow=1;
        while(pow*2<=n) pow*=2;
        if(pow==n) return true;
        return false;
    }
};
int main()
{
    Solution s;
    int n=1;
    (s.isPowerOfTwo(n))?cout<<"true":cout<<"false";
    return 0;
}
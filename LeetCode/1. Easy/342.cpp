#include<iostream>
using namespace std;
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        long pow=1;
        while(pow*4<=n) pow*=4;
        if(pow==n) return true;
        return false;
    }
};
int main()
{
    Solution s;
    int n=1;
    (s.isPowerOfFour(n))?cout<<"true":cout<<"false";
    return 0;
}
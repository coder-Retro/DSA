#include<iostream>
using namespace std;
class Solution
{
public:
    double myPow(double x,int n)
    {
        long power=n;
        double ans=1;
        if(n<0)
        {
            power=-power;
            x=1/x;
        }
        while(power>0)
        {
            if(power%2==1) ans*=x;
            x*=x;
            power/=2;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout<<s.myPow(2,3);
    return 0;
}
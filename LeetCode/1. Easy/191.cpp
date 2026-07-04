#include<iostream>
using namespace std;
class Solution
{
public:
    int hammingWeight(int n) {
        int count=0;
        long long power=1;
        while(power*2<=n) power*=2;
        while(power)
        {
            if(power<=n)
            {   
                count++;
                n-=power;
            }
            power/=2;
        }
        return count;
    }
};
int main()
{
    Solution s;
    int n=11;
    cout<<s.hammingWeight(n);
    return 0;
}
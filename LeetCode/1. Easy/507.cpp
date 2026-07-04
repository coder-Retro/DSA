#include<iostream>
using namespace std;
class Solution
{
public:
    bool checkPerfectNumber(int num) {
        int sum=0;
        for(int i=1;i<=num/2;i++)
        {
            if(num%i==0) sum+=i;
        }
        if(sum==num) return true;
        return false;
    }
};
int main()
{
    Solution s;
    int num=28;
    (s.checkPerfectNumber(num))?cout<<"true":cout<<"false";
    return 0;
}
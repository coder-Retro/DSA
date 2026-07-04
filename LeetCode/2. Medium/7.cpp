#include<iostream>
using namespace std;
class Solution
{
public:
    int reverse(int x) {
        long rev=0;
        while(x!=0)
        {
            rev=rev*10+x%10;
            x/=10;
        }
        if(rev<-2147483648||rev>2147483647) return 0;
        return rev;
    }
};
int main()
{
    Solution s;
    int a[4]={123,-123,120,1534236469};
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
        cout<<s.reverse(a[i])<<'\n';
    return 0;
}
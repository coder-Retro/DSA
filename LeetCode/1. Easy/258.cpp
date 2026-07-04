#include<iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        int sum=0;
        while(num)
        {
            sum+=(num%10);
            num/=10;
        }
        return addDigits(sum);
    }
};
int main()
{
    Solution s;
    int  num=38;
    cout<<s.addDigits(num);
    return 0;
}
#include<iostream>
using namespace std;
class Solution
{
public:
    int sum(int num1,int num2){
        return num1+num2;
    }
};
int main()
{
    Solution s;
    int num1=12;
    int num2=5;
    cout<<s.sum(num1,num2);
    return 0;
}
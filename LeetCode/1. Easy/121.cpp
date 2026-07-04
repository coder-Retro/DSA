#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int min=prices[0],maxProfit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<min) min=prices[i];
            if(maxProfit<prices[i]-min) maxProfit=prices[i]-min;
        }
        return maxProfit;
    }
};
int main()
{
    Solution s;
    vector<int> p1={7,1,5,3,6,4},p2={7,6,4,3,1},p3={2,1,4};
    cout<<s.maxProfit(p1)<<'\n';
    cout<<s.maxProfit(p2)<<'\n';
    cout<<s.maxProfit(p3)<<'\n';
    return 0;
}
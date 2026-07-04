#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<minPrice) minPrice=prices[i];
            if(i<prices.size()-1&&prices[i]>prices[i+1])
            {
                profit+=prices[i]-minPrice;
                minPrice=prices[i];
            }
            if(i==prices.size()-1)
            {
                profit+=prices[i]-minPrice;
            }
        }
        return profit;
    }
};
int main()
{
    Solution s;
    vector<int> p1={7,1,5,3,6,4},p2={1,2,3,4,5},p3={7,6,4,3,1};
    cout<<s.maxProfit(p1)<<'\n';
    cout<<s.maxProfit(p2)<<'\n';
    cout<<s.maxProfit(p3)<<'\n';
    return 0;
}
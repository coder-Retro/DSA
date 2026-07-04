#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution
{
public:
    int buyChoco(vector<int>& prices, int money) {
        if(prices.size()<2) return money;
        int diff=0;
        multiset<int> ms;
        multiset<int>::iterator choc;
        for(int i:prices)
            ms.insert(i);
        choc=next(ms.begin(),0);
        diff+= *choc;
        choc=next(ms.begin(),1);
        diff+= *choc;
        if(money-diff>=0) return money-diff;
        return money;
    }
};
int main()
{
    Solution s;
    vector<int> prices={3,2,5,7,3,2};
    int money=10;
    cout<<s.buyChoco(prices,money);
    return 0;
}
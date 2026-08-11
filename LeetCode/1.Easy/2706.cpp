#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
Approach: Min Tracking
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int m1=INT_MAX,m2=INT_MAX;
        for(int price:prices) {
            if(price<m1) {
                m2=m1;
                m1=price;
            } else if(price<m2) m2=price;
        }
        int diff=money-(m1+m2);
        return (diff>=0)?diff:money;
    }
};

int main() {
    Solution obj;
    vector<int> prices={3,2,5,7,3,2};
    int money=10;
    cout<<obj.buyChoco(prices,money);
    return 0;
}
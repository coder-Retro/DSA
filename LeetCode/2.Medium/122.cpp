#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Greedy / Max Tracking
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        // Adding the profit when price increases
        for (size_t i=1;i<prices.size();i++) {
            // Adding the profit when price increases
            if (prices[i]>prices[i-1]) {
                maxProfit+=prices[i]-prices[i-1];
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> p={{7,1,5,3,6,4},{1,2,3,4,5},{7,6,4,3,1}};
    for(vector<int>& v:p)
        cout<<obj.maxProfit(v)<<'\n';
    return 0;
}
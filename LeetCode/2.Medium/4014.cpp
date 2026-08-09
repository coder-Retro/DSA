#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Reverse Sort / Greedy
TC: O(max(n log n, m log m)), n and m are sizes of prices and discounts arrays
SC: O(max(log n, log m)), n and m are sizes of prices and discounts arrays
*/

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        double sum = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(i < discounts.size()) sum += prices[i] * (100 - discounts[i]) / 100.0;
            else                     sum += prices[i];
        }
        return sum;
    }
};

/*
Explanation:
We want to apply maximum discounts so we need to pair the max
discount with the max price, that is why we sort both arrays
in reverse order using rbegin() and rend(). Now we run a loop
from i = 0 to i < prices.size(). Discounts are only applied
while i < discounts.size(), since there are only that many
discounts available in total. Once every discount has been 
assigned to a price, any remaining prices are added at full
value. This is the Greedy approach where we maximize the applied
discount's effect using max to max matching.
*/

int main() {
    Solution obj;
    vector<int> prices = {10, 30, 21};
    vector<int> discounts = {50, 60};
    cout << obj.minPrice(prices, discounts);
    return 0;
}
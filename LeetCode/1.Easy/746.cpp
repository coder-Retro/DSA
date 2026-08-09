#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Dynamic Programming
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i = 2; i < n; i++) cost[i] += min(cost[i-1], cost[i-2]);
        return min(cost[n-1], cost[n-2]);
    }
};
int main() {
    Solution obj;
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout << obj.minCostClimbingStairs(cost);
    return 0;
}
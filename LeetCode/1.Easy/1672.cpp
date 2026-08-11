#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Max Row Sum
TC: O(m*n), m and n are number of customers and their banks
SC: O(1)
*/

class Solution {
public:
    int maxWealth(vector<vector<int>>& accounts) {
        int maxW=0;
        for(vector<int>& account:accounts) {
            int currW=0;
            for(int money:account) currW+=money;
            maxW=max(maxW, currW);
        }
        return maxW;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> accounts={{2,8,7},{7,1,3},{1,9,5}};
    cout<<obj.maxWealth(accounts);
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Sorting / Difference Accumulation
TC: O(n log n)
SC: O(1)
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves=0;
        int median=nums[nums.size()/2];
        for(int num:nums) moves+=abs(median-num);
        return moves;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,10,2,9};
    cout<<obj.minMoves2(nums);
    return 0;
}
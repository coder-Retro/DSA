#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: Count Accumulation / Linear Pass
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int curr=1,maxL=1;
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i]<nums[i+1]) curr++;
            else curr=1;
            maxL=max(maxL,curr);
        }
        return maxL;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,3,5,4,7};
    cout<<obj.findLengthOfLCIS(nums);
    return 0;
}
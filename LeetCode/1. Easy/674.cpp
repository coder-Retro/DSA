#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int curr=1,maxL=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1]) curr++;
            else curr=1;
            maxL=max(maxL,curr);
        }
        return maxL;
    }
};
int main() {
    Solution s;
    vector<int> nums={1,3,5,4,7};
    cout<<s.findLengthOfLCIS(nums);
    return 0;
}
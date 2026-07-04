#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0,j=nums.size()-1;i<j;)
        {
            if(nums[i]+nums[j]<target)
                i++;
            else if(nums[i]+nums[j]>target)
                j--;
            else
                return {i+1,j+1};
        }
        return {};
    }
};
int main() {
    Solution s;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> ans=s.twoSum(nums,target);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
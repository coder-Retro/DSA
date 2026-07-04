#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        if(nums.size()==1) return 0;
        for(int i=1;i<nums.size()-1;i++)
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) return i;
        if(nums[0]>nums[1]) return 0;
        else return nums.size()-1;
    }
};
int main()
{
    Solution s;
    vector<int> nums={1,2,1,3,5,6,4};
    cout<<s.findPeakElement(nums);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        if(nums.size()==1) return nums[0];
        int ans=nums[0];
        for(int i=0,min;i<nums.size()-1;i++)
        {
            min=i;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]<nums[min]) min=j;
            }
            if(i!=min) swap(nums[i],nums[min]);
        }
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i-1]&&nums[i]!=nums[i+1]) return nums[i];
        }
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums={2,2,3,2};
    cout<<s.singleNumber(nums);
    return 0;
}
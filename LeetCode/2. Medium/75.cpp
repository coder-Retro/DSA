#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        for(int i=0,min;i<nums.size()-1;i++)
        {
            min=i;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]<nums[min]) min=j;
            }
            if(i!=min) swap(nums[i],nums[min]);
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums={2,0,2,1,1,0};
    s.sortColors(nums);
    for(int i:nums) cout<<i<<" ";
    return 0;
}
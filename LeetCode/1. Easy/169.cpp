#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        // moore's algorithm
        int freq=0,ans;
        for(int i=0;i<nums.size();i++)
        {
            if(freq==0) ans=nums[i];
            if(ans==nums[i]) freq++;
            else freq--;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums={1,2,2,1,1};
    cout<<s.majorityElement(nums);
    return 0;
}
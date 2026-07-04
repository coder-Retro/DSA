#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int>& nums,int val)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            {
                for(int j=i;j<nums.size()-1;j++)
                    nums[j]=nums[j+1];
                i--;
                nums.pop_back();
            }
        }
        return nums.size();
    }
};
int main()
{
    Solution s;
    vector<int> nums={0,1,2,2,3,0,4,2};
    int val=2;
    cout<<s.removeElement(nums,val)<<'\n';
    for(int i:nums) cout<<i<<" ";
    return 0;
}
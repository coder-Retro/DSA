#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int>& nums)
    {
        int maxArea=0,currentArea;
        for(int i=0,j=nums.size()-1;i<j;)
        {
            if(nums[i]<nums[j])
            {
                currentArea=nums[i]*(j-i);
                i++;
            }
            else
            {
                currentArea=nums[j]*(j-i);
                j--;
            }
            if(maxArea<currentArea) maxArea=currentArea;
        }
        return maxArea;
    }
};
int main()
{
    Solution s;
    vector<int> container={1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(container);
    return 0;
}
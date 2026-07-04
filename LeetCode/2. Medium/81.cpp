#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]==target)
                return true;
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums={2,5,6,0,0,1,2};
    int target=0;
    if(s.search(nums,target))
        cout<<"Target Exists";
    else
        cout<<"Target Doesn't Exist";
    return 0;
}
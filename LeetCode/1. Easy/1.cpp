#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        vector<int> r;
        unordered_map<int,int> m;
        unordered_map<int,int>::iterator it;
        for(int i=0;i<nums.size();i++)
        {
            it=m.find(target-nums[i]);
            if(it!=m.end())
            {
                r.push_back(it->second);
                r.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return r;
    }
};
int main()
{
    Solution s;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> result=s.twoSum(nums,target);
    for(int i:result)
        cout<<i<<" ";
    return 0;
}
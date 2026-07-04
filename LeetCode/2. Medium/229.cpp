#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums){
        vector<int> v;
        unordered_map<int,int> freq;
        for(int i:nums) freq[i]++;
        for(auto& [key,value]:freq)
            if(value>nums.size()/3) v.push_back(key);
        return v;
    }
};
int main()
{
    Solution s;
    vector<int> nums={3,2,3};
    vector<int> ans=s.majorityElement(nums);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
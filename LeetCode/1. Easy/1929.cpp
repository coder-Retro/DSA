#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size()*2);
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            ans[i+nums.size()]=nums[i];
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums={1,2,1};
    vector<int> ans=s.getConcatenation(nums);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
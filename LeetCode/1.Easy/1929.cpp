#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Linear Concatenation
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size()*2);
        for(int i=0;i<nums.size();i++) {
            ans[i]=nums[i];
            ans[i+nums.size()]=nums[i];
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,2,1};
    vector<int> ans=obj.getConcatenation(nums);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
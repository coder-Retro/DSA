#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: Recursion / DFS
TC: O(n! * n)
SC: O(n! + n)
*/

class Solution {
    void dfs(vector<int>& nums,vector<vector<int>>& ans,int level) {
        if(level==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=level;i<nums.size();i++) {
            swap(nums[level],nums[i]);
            dfs(nums,ans,level+1);
            swap(nums[level],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums,ans,0);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,2,3};
    vector<vector<int>> perms=obj.permute(nums);
    for(vector<int>& v:perms) {
        for(int i:v) cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}
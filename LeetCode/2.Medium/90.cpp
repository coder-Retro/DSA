#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Recursion / Backtracking
TC: O(n 2ⁿ)
SC: O(n 2ⁿ)
*/

class Solution {
    void helper(const vector<int>& v,vector<int>& curr,vector<vector<int>>& subs,int level) {
        // Base Case Reached, Push Subset
        if(level==v.size()) {
            subs.push_back(curr);
            return;
        }
        // Include Current Value
        curr.push_back(v[level]);
        helper(v,curr,subs,level+1);
        // Backtracking
        curr.pop_back();
        // Skip Duplicates
        while(level<v.size()-1 && v[level]==v[level+1]) level++;
        helper(v,curr,subs,level+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subs;
        vector<int> curr;
        helper(nums,curr,subs,0);
        return subs;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,2,2};
    vector<vector<int>> subs=obj.subsetsWithDup(nums);
    for(vector<int>& v:subs) {
        for(int i:v) cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}
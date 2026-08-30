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
        if(level==v.size()) {
            subs.push_back(curr);
            return;
        }
        curr.push_back(v[level]);
        helper(v,curr,subs,level+1);
        curr.pop_back();
        helper(v,curr,subs,level+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> curr;
        helper(nums,curr,subs,0);
        reverse(subs.begin(),subs.end());
        return subs;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,2,3};
    vector<vector<int>> subs=obj.subsets(nums);
    for(vector<int>& v:subs) {
        for(int i:v) cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}
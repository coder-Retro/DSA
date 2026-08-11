#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Prefix Sum
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums);
        for(int i=1;i<ans.size();i++) ans[i]+=ans[i-1];
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums={3,1,2,10,1};
    vector<int> ans=obj.runningSum(nums);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
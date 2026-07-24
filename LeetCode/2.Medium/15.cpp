#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Sorting / Three Pointers
TC: O(n²)
SC: O(n²)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++) {
            if(i && nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(j<k) {
                int sum=nums[i]+nums[j]+nums[k];
                if(!sum) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++,k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(sum<0) j++;
                else           k--;
            }
        }
        return ans;
    }
};
int main() {
    Solution obj;
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=obj.threeSum(nums);
    cout<<'[';
    for(int i=0;i<ans.size();i++) {
        cout<<'[';
        for(int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j];
            if(j!=ans[i].size()-1) cout<<',';
        }
        cout<<']';
        if(i!=ans.size()-1) cout<<',';
    }
    cout<<']';
    return 0;
}
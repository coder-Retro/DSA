#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Sorting / Four Pointers
TC: O(n³)
SC: O(n⁴)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++) {
            if(i && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1,l=nums.size()-1;
                while(k<l) {
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target) {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++,l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target) k++;
                    else                l--;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution obj;
    vector<int> nums={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> ans=obj.fourSum(nums,target);
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
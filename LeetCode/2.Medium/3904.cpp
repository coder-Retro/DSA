#include<iostream>
#include<vector>
#include<algorithm>

/*
Approach: Prefix-Max / Suffix-Min
TC: O(n)
SC: O(n)
*/

class Solution {
    vector<int> suffixMin(const vector<int>& v) {
        int n=v.size();
        vector<int> mins(n,0);
        int minVal=INT_MAX;
        for(int i=n-1;i>=0;i--) {
            minVal=min(minVal,v[i]);
            mins[i]=minVal;
        }
        return mins;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> mins=suffixMin(nums);
        int maxs=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            maxs=max(maxs,nums[i]);
            if(maxs-mins[i]<=k) return i;
        }
        return -1;
    }
};

int main() {
    Solution obj;
    vector<int> nums={5,0,1,4};
    int k=3;
    cout<<obj.firstStableIndex(nums,k);
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Sorting / Linear Search
TC: O(n log n)
SC: O(1)
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ref=k;
        for(int i:nums) if(i==ref && i%k==0) ref+=k;
        return k;
    }
};

int main() {
    Solution obj;
    vector<int> nums={8,2,3,4,6};
    int k=2;
    cout<<obj.missingMultiple(nums,k);
    return 0;
}
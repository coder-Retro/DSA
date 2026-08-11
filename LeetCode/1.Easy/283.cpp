#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: Two Pointers
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int l=0,r=0;r<nums.size();r++)
            if(nums[r]) swap(nums[l++],nums[r]);
    }
};

int main() {
    Solution obj;
    vector<int> nums={0,1,0,3,12};
    obj.moveZeroes(nums);
    for(int i:nums) cout<<i<<" ";
    return 0;
}
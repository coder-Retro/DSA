#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0,j=i+1;j<nums.size();j++) {
            if(!nums[i] && nums[j]) {
                swap(nums[i],nums[j]);
                i++;
                j=i;
            } else if(nums[i]) {
                i++;
            }
        }
    }
};
int main() {
    Solution s;
    vector<int> nums={0,1,0,3,12};
    s.moveZeroes(nums);
    for(int i:nums) cout<<i<<" ";
    return 0;
}
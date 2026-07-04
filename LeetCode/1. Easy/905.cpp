#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i=0,evenIndex;i<nums.size();i++) {
            evenIndex=i;
            for(int j=i+1;j<nums.size();j++)
                if(nums[evenIndex]%2 && !(nums[j]%2)) evenIndex=j;
            if(i!=evenIndex) swap(nums[i],nums[evenIndex]);
        }
        return nums;
    }
};
int main() {
    Solution s;
    vector<int> nums={3,1,2,4};
    nums=s.sortArrayByParity(nums);
    for(int i:nums) cout<<i<<" ";
    return 0;
}
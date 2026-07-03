#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void exchangeSort(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1,temp;j<nums.size();j++)
                if(nums[i]>nums[j]) swap(nums[i],nums[j]);
        }
    }
};
int main() {
    Solution s;
    vector<int> nums[3]={{2,0,4,5,1,3},{2,1,2},{13,4,51,2,6,73,7,8}};
    for(int i=0;i<3;i++) {
        s.exchangeSort(nums[i]);
        for(int j:nums[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Brute Force
TC: O(n²)
SC: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i]==nums[j]) {
                    for(int k=j;k<nums.size()-1;k++)
                        nums[k]=nums[k+1];
                    j--;
                    nums.pop_back();
                }
            }
        }
        return nums.size();
    }
};

int main() {
    Solution obj;
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    obj.removeDuplicates(nums);
    for(int i:nums) cout<<i<<" ";
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Binary Search / Duplicate Detection
TC: O(log n)
SC: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r) {
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r])       l=mid+1;
            else if(nums[mid]<nums[r])  r=mid;
            else                        r--;
        }
        return nums[l];
    }
};
int main() {
    Solution s;
    vector<int> nums={2,2,2,0,1};
    cout<<s.findMin(nums);
    return 0;
}
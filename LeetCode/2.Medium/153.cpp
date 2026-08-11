#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Binary Search
TC: O(log n)
SC: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r) {
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else                  r=mid;
        }
        return nums[l];
    }
};

int main() {
    Solution obj;
    vector<int> nums={3,4,5,1,2};
    cout<<obj.findMin(nums);
    return 0;
}
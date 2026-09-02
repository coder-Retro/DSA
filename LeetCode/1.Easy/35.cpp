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
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1; 
        while (low<=high) {
            int mid=low+(high-low)/2;
            if (nums[mid]==target)     return mid; // Target found
            else if (nums[mid]<target) low=mid+1;  // Target is in the right half
            else                       high=mid-1; // Target is in the left half
        }
        return low;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,3,5,6};
    int target=4;
    cout<<obj.searchInsert(nums, target);
    return 0;
}
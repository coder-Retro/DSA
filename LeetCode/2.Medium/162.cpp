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
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int i=0,j=nums.size()-1;
        while(i<j) {
            int mid=i+(j-i)/2;
            if(nums[mid]<nums[mid+1]) i=mid+1;
            else                      j=mid;
        }
        return i;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,2,1,3,5,6,4};
    cout<<obj.findPeakElement(nums);
    return 0;
}
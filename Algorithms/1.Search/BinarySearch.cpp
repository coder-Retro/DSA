#include<iostream>
#include<vector>
using namespace std;

/*
Use Case:
Binary search algorithm is used to find a value
in large but sorted dataset in logarithmic time.
It works by comparing the target value with the
middle element of dataset to determine if target
lives in the left half or the right half and the
loops on till target is found. If range narrows
down to a single element and the target is still
not found, then -1 is returned as sign showing
the absence of target element in the dataset.
*/

/*
Approach: Binary Search
TC: O(log n)
SC: O(1)
*/

class Solution {
public:
    int binarySearch(vector<int>& nums,int target) {
        if(nums.size()==0) return -1;
        int i=0;
        int j=nums.size()-1;
        int mid;
        while(i<=j) {
            mid=i+(j-i)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) i=mid+1;
            if(nums[mid]>target) j=mid-1;
        }
        return -1;
    }
};
int main() {
    Solution s;
    vector<int> nums;
    for(int i=0;i<100;i++) nums.push_back(i+1);
    cout<<s.binarySearch(nums,50);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
Binary Search:
This pattern is only applicable where data is sorted.
Data can be rotated but overall it should still be in
sorted order. This algo works by comparing the target
we are looking for with the mid value of our sorted
dataset — if mid equals target, target is found. But
before applying this logic, we must first find which
sorted region our target is present in. If both the
left and right end become equal and target still isn't
found, then target doesn't exist in that dataset and -1
is returned as an invalid index. The time complexity of
this algo is O(log n) and the space complexity is O(1)
because it uses constant space regardless of dataset size.

Summary:
This algorithm works by finding which half of the array
(left of mid, or right of mid) is currently sorted, then
checking whether the target falls within that sorted half's
value range. If it does, search continues in that half;
otherwise, search continues in the other half. This handles
rotation correctly, since a plain "target vs mid" comparison
only works on an array that isn't rotated.
*/

// Binary Search Function
int searchRotatedSortedArr(vector<int>& nums,int target) {
    if(nums.empty()) return -1; // Checking Empty Vector
    if(nums[0]==target) return 0; // First Element is Target
    // Binary Search Pattern
    int i=0,j=nums.size()-1;
    int mid;
    while(i<=j) {
        mid=i+(j-i)/2;
        if(nums[mid]==target) break; // Target Found at mid
        // Can't tell which half is sorted (Duplicates Exist)
        if (nums[i] == nums[mid] && nums[mid] == nums[j]) {
            i++;
            j--;
        } // Left Half is Sorted
        else if(nums[i]<=nums[mid]) { 
            if(nums[i]<=target && target<nums[mid])
                j=mid-1;
            else
                i=mid+1;
        } // Right Half is Sorted
        else { 
            if(nums[mid]<target && target<=nums[j])
                i=mid+1;
            else
                j=mid-1;
        }
    }
    // Finding First Occurence of Target (If Duplicates Exist)
    while(mid>0 && nums[mid]==target) {
        if(nums[mid-1]==target) mid--;
        else return mid;
    }
    // Target Not Found
    return -1;
}
// Main Function
int main() {
    vector<int> nums={1,1,1,2,2,2,3,3,3};  //{4,5,6,7,8,9,0,1,2,3};
    int target=2;
    cout<<searchRotatedSortedArr(nums,target);
    return 0;
}
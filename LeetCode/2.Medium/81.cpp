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
    bool search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        int mid;
        while(i<=j) {
            mid=i+(j-i)/2;
            if(nums[mid]==target) return true;
            if(nums[i]==nums[mid] && nums[mid]==nums[j]) i++,j--;
            // Left Half is Sorted
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
        return false;
    }
};

int main() {
    Solution obj;
    vector<int> nums={2,5,6,0,0,1,2};
    int target=1;
    if(obj.search(nums,target)) cout<<"Target Exists";
    else                        cout<<"Target Doesn't Exist";
    return 0;
}
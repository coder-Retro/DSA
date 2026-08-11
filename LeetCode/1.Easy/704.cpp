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
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)     return mid;
            else if(nums[mid]<target) l=mid+1;
            else                      r=mid-1;
        }
        return -1;
    }
};

int main() {
    Solution obj;
    vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    int target=4;
    int index=obj.search(vec,target);
    if(index==-1) cout<<target<<" not found in array.";
    else          cout<<target<<" found at index : "<<index;
    return 0;
}
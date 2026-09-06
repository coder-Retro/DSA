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
        int i=1,j=1;
        while(j<nums.size()) {
            if(nums[j]!=nums[i-1]) nums[i++]=nums[j];
            j++;
        }
        return i;
    }
};

int main() {
    Solution obj;
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    int newSize=obj.removeDuplicates(nums);
    for(int i=0;i<newSize;i++) {
        cout<<nums[i]<<" ";
    }
    return 0;
}
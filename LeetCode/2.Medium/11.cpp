#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Two Pointer / Max Tracking
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& nums) {
        int maxA=0,currA=0;
        int i=0,j=nums.size()-1;
        while(i<j) {
            if(nums[i]<nums[j]) currA=nums[i]*(j-(i++));
            else                currA=nums[j]*((j--)-i);
            maxA=max(maxA,currA);
        }
        return maxA;
    }
};

int main() {
    Solution s;
    vector<int> container={1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(container);
    return 0;
}
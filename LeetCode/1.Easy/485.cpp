#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Iterative Accumulation / Linear Pass
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOne=0;
        int curr=0;
        for(int i:nums)
            if(i==1) {
                curr++;
                maxOne=max(maxOne,curr);
            }
            else curr=0;
        return maxOne;
    }
};
int main() {
    Solution s;
    vector<int> nums={1,1,0,1,1,1};
    cout<<s.findMaxConsecutiveOnes(nums);
    return 0;
}
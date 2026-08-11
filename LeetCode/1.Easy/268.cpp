#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Bit Manipulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing=nums.size();
        int n=0;
        for(int i:nums) {
            missing ^= (n++) ^ i;
        }
        return missing;
    }
};

int main() {
    Solution obj;
    vector<int> nums={3,0,1};
    cout<<obj.missingNumber(nums);
    return 0;
}
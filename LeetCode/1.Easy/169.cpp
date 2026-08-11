#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Boyer Moore Algo
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's algorithm
        int freq=0,ans;
        for(int i=0;i<nums.size();i++) {
            if(freq==0) ans=nums[i];
            if(ans==nums[i]) freq++;
            else freq--;
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,2,2,1,1};
    cout<<obj.majorityElement(nums);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int curr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                curr++;
            else
                curr=0;
            if(curr>max)
                max=curr;
        }
        return max;
    }
};
int main() {
    Solution s;
    vector<int> nums={1,1,0,1,1,1};
    cout<<s.findMaxConsecutiveOnes(nums);
    return 0;
}
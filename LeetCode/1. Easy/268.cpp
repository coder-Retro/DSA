#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int maxSum=n*(n+1)/2;
        int sum=0;
        for(int i:nums) sum+=i;
        return maxSum-sum;
    }
};
int main() {
    Solution s;
    vector<int> nums={3,0,1};
    cout<<s.missingNumber(nums);
    return 0;
}
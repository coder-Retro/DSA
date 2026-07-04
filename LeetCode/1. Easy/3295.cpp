#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans(nums.size()*2);
        int i=0,j=ans.size()-1;
        while(i<j) {
            ans[i]=nums[i];
            ans[j--]=nums[i++];
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums={1,2,3};
    vector<int> ans=s.concatWithReverse(nums);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
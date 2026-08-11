#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Two Pointers
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int i=0,j=n-1,k=n-1;
        while(i<=k) {
            long s1=(long)nums[i]*nums[i];
            long s2=(long)nums[j]*nums[j];
            if(s1>s2) { ans[k--]=s1; i++; }
            else      { ans[k--]=s2; j--; }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums={-4,-1,0,3,10};
    vector<int> ans=obj.sortedSquares(nums);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
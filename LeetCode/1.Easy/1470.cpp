#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Parity Based Writing
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(n*2);
        for(int i=0,j=0,k=n;i<n*2;i++)
            if(i%2==0) ans[i]=nums[j++];
            else       ans[i]=nums[k++];
        return ans;
    }
};
int main() {
    Solution obj;
    vector<int> nums={1,2,3,4,4,3,2,1};
    int n=4;
    vector<int> ans=obj.shuffle(nums, n);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
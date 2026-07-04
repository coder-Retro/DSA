#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums,int target) {
        if(!nums.size()) return {-1,-1};
        int l=0,r=nums.size()-1;
        int mid;
        while(l<=r) {
            mid=l+(r-l)/2;
            if(nums[mid]==target)     break;
            else if(nums[mid]<target) l=mid+1;
            else                      r=mid-1;
        }
        if(nums[mid]!=target) return{-1,-1};
        l=r=mid;
        while(l>0 && nums[l-1]==target)             l--;
        while(r<nums.size()-1 && nums[r+1]==target) r++;
        return {l,r};
    }
};
int main() {
    Solution s;
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    vector<int> ans=s.searchRange(nums,target);
    cout<<'['<<ans[0]<<','<<ans[1]<<']';
    return 0;
}
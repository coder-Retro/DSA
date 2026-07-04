#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums,int k) {
        int siz=nums.size();
        if(!siz || !k) return;
        k%=siz;
        int i,j;
        for(i=0,j=siz-1;i<j;i++,j--)
            swap(nums[i],nums[j]);
        for(i=0,j=k-1;i<j;i++,j--)
            swap(nums[i],nums[j]);
        for(i=k,j=siz-1;i<j;i++,j--)
            swap(nums[i],nums[j]);
    }
};
int main() {
    Solution s;
    vector<int> nums={1,2,3,4,5};
    int k=2;
    s.rotate(nums,k);
    for(int i:nums) cout<<i<<" ";
    return 0;
}
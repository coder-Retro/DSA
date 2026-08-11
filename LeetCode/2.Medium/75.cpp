#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: Dutch National Flag Algo
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,m=0,h=nums.size()-1;
        while(m<=h)
            if     (nums[m]==0) swap(nums[m++],nums[l++]);
            else if(nums[m]==1) m++;
            else                swap(nums[m],nums[h--]);
    }
};

int main() {
    Solution obj;
    vector<int> nums={2,0,2,1,1,0};
    obj.sortColors(nums);
    for(int i:nums) cout<<i<<" ";
    return 0;
}
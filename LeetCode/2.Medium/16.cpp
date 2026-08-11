#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Sorting / Three Pointers
TC: O(n²)
SC: O(1)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1,k=nums.size()-1;j<k;) {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target)                     return sum;
                if(abs(target-sum)<abs(target-ans)) ans=sum;
                if(sum<target)                      j++;
                else                                k--;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums={-1,2,1,-4};
    int target=1;
    cout<<obj.threeSumClosest(nums,target);
    return 0;
}
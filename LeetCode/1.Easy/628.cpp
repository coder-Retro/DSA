#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
Approach: Max Tracking / Min Tracking
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int l1=INT_MIN,l2=INT_MIN,l3=INT_MIN;
        int s1=INT_MAX,s2=INT_MAX;
        for(int i:nums) {
            // Max Tracking
            if(i>=l1)      l3=l2,l2=l1,l1=i;
            else if(i>=l2) l3=l2,l2=i;
            else if(i>l3)  l3=i;
            // Min Tracking
            if(i<=s1)     s2=s1,s1=i;
            else if(i<s2) s2=i;
        }
        return max(l1*l2*l3,s1*s2*l1);
    }
};
int main() {
    Solution obj;
    vector<int> nums={-1,-2,-3};
    cout<<obj.maximumProduct(nums);
    return 0;
}
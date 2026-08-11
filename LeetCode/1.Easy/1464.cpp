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
    int maxProduct(vector<int>& nums) {
        int l1=INT_MIN,l2=INT_MIN;
        int s1=INT_MAX,s2=INT_MAX;
        for(int i:nums) {
            // Max Tracking
            if(i>=l1)     l2=l1,l1=i;
            else if(i>l2) l2=i;
            // Min Tracking
            if(i<=s1)     s2=s1,s1=i;
            else if(i<s2) s2=i;
        }
        return max((l1-1)*(l2-1),(s1-1)*(s2-1));
    }
};

int main() {
    Solution obj;
    vector<int> nums={3,4,5,2};
    cout<<obj.maxProduct(nums);
    return 0;
}
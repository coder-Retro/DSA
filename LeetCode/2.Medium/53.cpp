#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
Approach: Kadane's Algo / Dynamic Programming
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current=0,max=INT_MIN;
        for(int i:nums) {
            current+=i;
            if(max<current) max=current;
            if(current<0)   current=0;
        }
        return max;
    }
};a

int main() {
    Solution obj;
    vector<int> nums={3,-4,5,4,-1,7,-8};
    cout<<obj.maxSubArray(nums);
    return 0;
}
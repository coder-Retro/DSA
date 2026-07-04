#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algorithm
        int current=0,max=INT_MIN;
        for(int i:nums) {
            current+=i;
            if(max<current) max=current;
            if(current<0) current=0;
        }
        return max;
    }
};
using namespace std;
int main() {
    Solution s;
    vector<int> nums={3,-4,5,4,-1,7,-8};
    cout<<s.maxSubArray(nums);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Modulo Digit Extraction
TC: O(n)
SC: O(1)
*/

class Solution {
    int digitSum(int n) {
        int sum=0;
        while(n) { sum+=n%10; n/=10; }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int minIdx=-1;
        for(int i=0;i<nums.size();i++) {
            if(digitSum(nums[i])==i) {
                minIdx=i;
                break;
            }
        }
        return minIdx;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,10,11};
    cout<<obj.smallestIndex(nums)<<'\n';
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Simulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum=0;
        for(size_t i=0;i<nums.size();i++)
            if(nums.size()%(i+1)==0) sum+=nums[i]*nums[i];
        return sum;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> tests={{1,2,3,4},{2,7,1,19,18,3}};
    for(vector<int>& nums:tests)
        cout<<obj.sumOfSquares(nums)<<'\n';
    return 0;
}
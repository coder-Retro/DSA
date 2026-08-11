#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Bit Manipulation
TC: O(n)
SC: O(1)
*/

class Solution{
public:
    int singleNumber(vector<int>&nums) {
        // bitwise XOR cancellation
        int answer=0;
        for(int i:nums) answer^=i;
        return answer;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,1,7,3,3,4,4};
    cout<<"Single Number : "<<obj.singleNumber(nums);
    return 0;
}
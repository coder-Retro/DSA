#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int singleNumber(vector<int>&nums)
        {
            // bitwise XOR cancellation
            int answer=0;
            for(int i:nums)
                answer^=i;
            return answer;
        }
};
int main()
{
    Solution s;
    vector<int> nums={1,1,7,3,3,4,4};
    cout<<"Single Number : "<<s.singleNumber(nums);
    return 0;
}
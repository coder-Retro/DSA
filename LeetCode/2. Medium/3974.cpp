#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long maxSum(vector<int>& nums,int k,int mul) {
        long long sum=0;
        sort(nums.begin(),nums.end());
        int i=nums.size()-1;
        while(k--) {
            if(nums[i]>(long long)nums[i]*mul) sum+=nums[i];
            else              sum+=((long long)nums[i]*mul);
            i--,mul--;
        }
        return sum;
    }
};
int main() {
    Solution s;
    vector<int> nums={6,1,2,9};
    int k=3;
    int mul=2;
    cout<<s.maxSum(nums,k,mul);
    return 0;
}
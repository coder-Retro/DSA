#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

/*
Approach: PrefixGCDs / Euclidean Algo / Sorting / Two Pointers 
TC: O(n log n)
SC: O(1)
*/

class Solution {
private:
    int euclidean(int a,int b) {
        while(b) { a%=b; swap(a,b); }
        return a;
    }
    void prefixGCD(vector<int>& nums) {
        int currMax=nums[0];
        for(int i=0;i<nums.size();i++) {
            currMax=max(currMax,nums[i]);
            nums[i]=euclidean(currMax,nums[i]);
        }
    }
public:
    long long gcdSum(vector<int>& nums) {
        prefixGCD(nums);
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        long long sum=0;
        while(i<j) sum+=euclidean(nums[i++],nums[j--]);
        return sum;
    }
};

int main() {
    Solution obj;
    vector<int> nums={3,6,2,8};
    cout<<obj.gcdSum(nums);
    return 0;
}
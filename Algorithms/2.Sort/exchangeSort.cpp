#include<iostream>
#include<vector>
using namespace std;

/*
Use Case:
Exchange sort algorithm is used to sort the dataset
in quadratic time, it is an even more unoptimized,
form of bubble sort algorithm as it doesn't detect
the absence of any swap and completes all of its
iterations regardless of dataset already being sorted.
It works similar to bubble sort by swapping the
adjacent elements and taking ith largest element
to the ith last index in each inner loop iteration.
*/

/*
Approach: Brute Force
TC: O(n²)
SC: O(1)
*/

class Solution {
public:
    void exchangeSort(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1,temp;j<nums.size();j++)
                if(nums[i]>nums[j]) swap(nums[i],nums[j]);
        }
    }
};
int main() {
    Solution s;
    vector<int> nums[3]={{2,0,4,5,1,3},{2,1,2},{13,4,51,2,6,73,7,8}};
    for(int i=0;i<3;i++) {
        s.exchangeSort(nums[i]);
        for(int j:nums[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
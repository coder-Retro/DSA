#include<iostream>
#include<vector>
using namespace std;

/*
Use Case:
Selection sort algorithm is used to sort the dataset
in quadratic time, it is one of the unoptimized,
slow and inefficient sorting algorithms. It works
finding the ith minimum element in each of inner
loop iteration and swaps if with the ith index from
start of the dataset. If only swaps if ith smallest
element isn't already on the ith index from the start.
*/

/*
Approach: Brute Force
TC: O(n²)
SC: O(1)
*/

class Solution {
public:
    void selectionSort(vector<int>& nums) {
        for(int i=0,minIndex;i<(int)nums.size();i++) {
            minIndex=i;
            for(int j=i+1;j<(int)nums.size();j++)
                if(nums[j]<nums[minIndex]) minIndex=j;
            if(i!=minIndex) swap(nums[i],nums[minIndex]);
        }
    }
};
int main() {
    Solution s;
    vector<int> nums[3]={{2,0,4,5,1,3},{2,1,2},{13,4,51,2,6,73,7,8}};
    for(int i=0;i<3;i++) {
        s.selectionSort(nums[i]);
        for(int j:nums[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
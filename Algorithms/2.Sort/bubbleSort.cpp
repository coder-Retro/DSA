#include<iostream>
#include<vector>
using namespace std;

/*
Use Case:
Bubble sort algorithm is used to sort the dataset
in quadratic time, it is one of the unoptimized,
slow and inefficient sorting algorithms. It works
by swapping the adjacent elements and taking ith
largest element to the ith last index in each inner
loop iteration. However, if no swap is detected in
an iteration then it terminates because data is
aleardy sorted by then.
*/

/*
Approach: Brute Force
TC: O(n²)
SC: O(1)
*/

class Solution {
public:
    void bubbleSort(vector<int>& nums) {
        bool isSwapped;
        for(int i=0;i<nums.size();i++) {
            isSwapped=false;
            for(int j=0;j<nums.size()-1-i;j++) {
                if(nums[j]>nums[j+1]) {
                    swap(nums[j],nums[j+1]);
                    isSwapped=true;
                }
            }
            if(!isSwapped) break;
        }
    }
};
int main() {
    Solution s;
    vector<int> nums[3]={{2,0,4,5,1,3},{2,1,2},{13,4,51,2,6,73,7,8}};
    for(int i=0;i<3;i++) {
        s.bubbleSort(nums[i]);
        for(int j:nums[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
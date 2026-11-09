#include<iostream>
#include<vector>
using namespace std;

/*
Use Case:
Insertion sort is an efficient algorithm for sorting small datasets or 
datasets that are already partially sorted. It builds the final sorted 
array one item at a time by taking an element from the unsorted portion 
and shifting all larger elements in the sorted portion one position to 
the right, effectively "inserting" the element into its correct position.
*/

/*
Approach: Brute Force
TC: O(n²)
SC: O(1)
*/

class Solution {
public:
    void insertionSort(vector<int>& nums) {
        for(int i=1,target,insertPoint;i<(int)nums.size();i++) {
            target=nums[i];
            insertPoint=i-1;
            while(insertPoint>=0 && nums[insertPoint]>target) {
                nums[insertPoint+1]=nums[insertPoint];
                insertPoint--;
            }
            nums[insertPoint+1]=target;
        }
    }
};
int main() {
    Solution s;
    vector<int> nums[3]={{2,0,4,5,1,3},{2,1,2},{13,4,51,2,6,73,7,8}};
    for(int i=0;i<3;i++) {
        s.insertionSort(nums[i]);
        for(int j:nums[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
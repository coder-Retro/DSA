#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void insertionSort(vector<int>& nums) {
        for(int i=1,target,insertPoint;i<nums.size();i++) {
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
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void selectionSort(vector<int>& nums) {
        for(int i=0,minIndex;i<nums.size();i++) {
            minIndex=i;
            for(int j=i+1;j<nums.size();j++)
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
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>& nums,int target) {
        if(nums.size()==0) return -1;
        int i=0;
        int j=nums.size()-1;
        int mid;
        while(i<=j) {
            mid=i+(j-i)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) i=mid+1;
            if(nums[mid]>target) j=mid-1;
        }
        return -1;
    }
};
int main() {
    Solution s;
    vector<int> nums;
    for(int i=0;i<100;i++) nums.push_back(i+1);
    cout<<s.binarySearch(nums,50);
    return 0;
}
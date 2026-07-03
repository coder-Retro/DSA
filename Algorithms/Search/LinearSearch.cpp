#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int linearSearch(vector<int>& nums,int target) {
        if(nums.size()==0) return -1;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==target) return i;
        return -1;
    }
};
int main() {
    Solution s;
    vector<int> nums;
    for(int i=0;i<100;i++) nums.push_back(i+1);
    cout<<s.linearSearch(nums,50);
    return 0;
}
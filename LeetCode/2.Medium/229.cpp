#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Approach: Hasihing
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums){
        vector<int> v;
        unordered_map<int,int> freq;
        for(int i:nums) freq[i]++;
        for(auto& [key,value]:freq)
            if(value>nums.size()/3) v.push_back(key);
        return v;
    }
};

int main() {
    Solution obj;
    vector<int> nums={3,2,3};
    vector<int> ans=obj.majorityElement(nums);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
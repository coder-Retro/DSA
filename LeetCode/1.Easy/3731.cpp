#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
using namespace std;

/*
Approach: Hashing / Range Scan
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> seen(nums.begin(),nums.end());
        int s=INT_MAX,e=INT_MIN;
        for(int i:nums) {
            if(i<s) s=i;
            if(i>e) e=i;
        }
        for(int i=s+1;i<e;i++)
            if(!seen.contains(i)) ans.push_back(i);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,4,2,5,9};
    vector<int> ans=obj.findMissingElements(nums);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
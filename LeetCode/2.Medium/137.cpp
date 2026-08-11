#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*
Approach: Hashing
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i:nums) m[i]++;
        for(auto it=m.begin();it!=m.end();it++)
            if(it->second<3) return it->first;
        return -1;
    }
};

int main() {
    Solution obj;
    vector<int> nums={2,2,3,2};
    cout<<obj.singleNumber(nums);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Hashing
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> hash(101,false);
        for(int i:nums) hash[i]=true;
        int ref=k;
        while(ref<=100 && hash[ref]) ref+=k;
        return ref;
    }
};

int main() {
    Solution obj;
    vector<int> nums={8,2,3,4,6};
    int k=2;
    cout<<obj.missingMultiple(nums,k);
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

/*
Approach: Hashing:
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(),nums.end());
        int maxLen=0;
        for(int num:hash) {
            if(hash.contains(num-1)) continue;
            int curr=num;
            int len=0;
            while(hash.contains(curr)) {
                len++;
                curr++;
            }
            maxLen=max(maxLen,len);
        }
        return maxLen;
    }
};

int main() {
    Solution obj;
    vector<int> nums={0,1,2,4,8,5,6,7,9,3,55,88,77,99,999999999};
    cout<<obj.longestConsecutive(nums);
    return 0;
}
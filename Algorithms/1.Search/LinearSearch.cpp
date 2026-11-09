#include<iostream>
#include<vector>
using namespace std;

/*
Use Case:
Linear search algorithm is used to find a value
in an unsorted dataset in linear time. It works
by iterating through the dataset from the start
and traversing till the end until the target is
found. If target is found then it's returned to
the call but if dataset ends and target is still
not found, then -1 is returned as a sign of the
absence of target element.
*/

/*
Approach: Linear Search
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int linearSearch(vector<int>& nums,int target) {
        if(nums.empty()) return -1;
        for(int i=0;i<(int)nums.size();i++)
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
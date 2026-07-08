#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
Approach: Min Heap
TC: O(n log n)
SC: O(1)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums,int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i:nums) {
            minHeap.push(i);
            if(minHeap.size()>k) minHeap.pop();
        }
        return minHeap.top();
    }
};
int main() {
    Solution s;
    vector<int> nums={3,2,3,1,2,4,5,5,6};
    int k=4;
    cout<<s.findKthLargest(nums,k);
    return 0;
}
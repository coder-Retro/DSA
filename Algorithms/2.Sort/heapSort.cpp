#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

/*
Use Case:
1. Systems with strict memory limits where O(1) auxiliary space is non-negotiable.
2. Safety-critical or real-time applications requiring a guaranteed O(n log n) worst-case time bound.
3. Used as a fallback routine in hybrid sorts (like IntroSort) to protect against QuickSort's worst-case degradation.
*/

/*
Approach: Max Heap
TC: O(n log n)
SC: O(1)
*/

class Solution {
    void heapify(vector<int>& nums,int n,int i) {
        while(true) {
            int largest=i;
            int l=i*2+1;
            int r=i*2+2;
            if (l<n && nums[l]>nums[largest]) largest=l;
            if (r<n && nums[r]>nums[largest]) largest=r;
            if(largest==i) break;
            swap(nums[i],nums[largest]);
            i=largest;
        }
    }
public:
    void heapSort(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--)
            heapify(nums,n,i);
        for(int i=n-1;i>0;i--) {
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
    }
};
int main() {
    Solution s;
    vector<int> nums[3]={{2,0,4,5,1,3},{2,1,2},{13,4,51,2,6,73,7,8}};
    for(int i=0;i<3;i++) {
        s.heapSort(nums[i]);
        for(int j:nums[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
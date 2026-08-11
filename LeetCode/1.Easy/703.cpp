#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Constructor:
Approach: Fixed Size MinHeap
TC: O(n log k)
SC: O(1)

add:
Approach: MinHeap Loading
TC: O(log k)
SC: O(1)
*/

class KthLargest {
    priority_queue<int,vector<int>,greater<int>> minheap;
    int k;
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for(int i:nums) {
            minheap.push(i);
            if(minheap.size()>k) minheap.pop();
        }
    }
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>k) minheap.pop();
        return minheap.top();
    }
};

int main() {
    vector<int> nums={4, 5, 8, 2};
    KthLargest obj(3, nums);
    cout<<'[';
    cout<<obj.add(3)<<", ";
    cout<<obj.add(5)<<", ";
    cout<<obj.add(10)<<", ";
    cout<<obj.add(9)<<", ";
    cout<<obj.add(4);
    cout<<']';
    return 0;
}
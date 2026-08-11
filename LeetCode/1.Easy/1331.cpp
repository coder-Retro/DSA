#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

/*
Approach: Min Heap / Min Index Tracking
TC: O(n log n)
SC: O(n)
*/

class Solution {
    struct Compare {
        bool operator()(pair<int,int>& a,pair<int,int>& b) {
            return a.second>b.second;
        }
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> minheap;
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
            minheap.push(pair{i,arr[i]});
        int rank=1;
        while(!minheap.empty()) {
            int prev=minheap.top().second;
            arr[minheap.top().first]=rank;
            minheap.pop();
            if(!minheap.empty() && prev!=minheap.top().second)
                rank++;
        }
        return arr;
    }
};

int main() {
    Solution obj;
    vector<int> arr={37,12,28,9,100,56,80,5,12};
    arr=obj.arrayRankTransform(arr);
    for(int i:arr) cout<<i<<" ";
    return 0;
}
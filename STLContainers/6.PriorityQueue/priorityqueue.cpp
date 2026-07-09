#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
Priority Queue although is called a queue but under the hood,
it basically works using the principals of minHeap/maxHeap so
we can say that it is basically a complete binary tree in the
disguise but it is implemented using a flat vector inside the
class itself. We can look at this phenomena by using following:
Min Heap:
    it keeps order by keeping the elements in such an order
that each node has a value less than or equal to its child
nodes. Meaning that the root is the smallest value in dataset.
Max Heap:
    it keeps order by keeping the elements in such an order
that each node has a value greater than or equal to its child
nodes. Meaning that the root is the largest value in dataset.
*/

int main()
{
    // Max Heap Declaration:
    priority_queue<int,vector<int>> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    // Pushing Integers into Heaps
    for(int i:{9,2,4,6,1,3,5,7,8,10,0}) {
        maxHeap.push(i);
        minHeap.push(i);
    }
    // Max Heap Elements:
    cout<<"Max Heap: ";
    while(!maxHeap.empty()) {
        cout<<maxHeap.top()<<" ";
        maxHeap.pop();
    }
    cout<<'\n';
    // Min Heap Elements:
    cout<<"Min Heap: ";
    while(!minHeap.empty()) {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    cout<<'\n';
    return 0;
}
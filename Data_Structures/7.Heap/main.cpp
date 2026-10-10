#include<iostream>
#include<vector>
#include"heap.h"
using namespace std;

int main() {
    Heap<int> minHeap({3,4,5,1,2});
    cout<<"Min Heap: ";
    cout<<'[';
    while(!minHeap.empty()) {
        cout<<minHeap.pop();
        if(minHeap.size()>0) cout<<',';
    }
    cout<<']';
    cout<<'\n';
    Heap<int,greater<int>> maxHeap({3,4,5,1,2});
    cout<<"Max Heap: ";
    cout<<'[';
    while(!maxHeap.empty()) {
        cout<<maxHeap.pop();
        if(maxHeap.size()>0) cout<<',';
    }
    cout<<']';
    return 0;
}
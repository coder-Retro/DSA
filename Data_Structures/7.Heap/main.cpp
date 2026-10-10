#include<iostream>
#include<vector>
#include"heap.h"
using namespace std;

// Custom Node Struct
struct Node {
    int val;
    Node* next;
    Node(int _val): val(_val), next(nullptr) {}
};
// Custom Comparator for MinHeap of Node*
struct MinCompare {
    bool operator()(Node* a,Node* b) const { return a->val < b->val; }
};
// Custom Comparator for MaxHeap of Node*
struct MaxCompare {
    bool operator()(Node* a,Node* b) const { return a->val > b->val; }
};

int main() {
    // Min & Max Heaps on int
    vector<int> vals={3,4,5,1,2};
    Heap<int,less<int>>    minHeap;
    Heap<int,greater<int>> maxHeap;
    for(int val:vals) {
        minHeap.push(val);
        maxHeap.push(val);
    }
    cout<<"Min Heap of int  : ";
    cout<<"[";
    while(!minHeap.empty()) {
        cout<<minHeap.pop();
        if(minHeap.size()>0) cout<<",";
    }
    cout<<"]\n";
    cout<<"Max Heap of int  : ";
    cout<<"[";
    while(!maxHeap.empty()) {
        cout<<maxHeap.pop();
        if(maxHeap.size()>0) cout<<",";
    }
    cout<<"]\n";
    // Min & Max Heaps of Node*
    vector<Node*> nodes;
    for(int val:vals) nodes.push_back(new Node(val));   
    Heap<Node*,MinCompare> minHeapNode;
    Heap<Node*,MaxCompare> maxHeapNode;
    for(Node* node:nodes) {
        minHeapNode.push(node);
        maxHeapNode.push(node);
    }
    cout<<"Min Heap of Node*: ";
    cout<<"[";
    while(!minHeapNode.empty()) {
        cout<<minHeapNode.pop()->val;
        if(!minHeapNode.empty()) cout<<",";
    }
    cout<<"]\n";
    cout<<"Max Heap of Node*: ";
    cout<<"[";
    while(!maxHeapNode.empty()) {
        cout<<maxHeapNode.pop()->val;
        if(!maxHeapNode.empty()) cout<<",";
    }
    cout<<"]\n";
    for(Node*& node:nodes) delete node;
    return 0;
}
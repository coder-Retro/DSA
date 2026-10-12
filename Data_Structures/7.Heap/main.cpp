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
    Heap<int,less<int>>    minHeap; // Min Heap using less<int> compare
    Heap<int,greater<int>> maxHeap; // Max Heap using greater<int> compares
    for(int val:vals) {
        minHeap.push(val); // Pushing To Min Heap
        maxHeap.push(val); // Pushing To Max Heap
    }
    cout<<"Min Heap of int  : ";
    cout<<"[";
    while(!minHeap.empty()) {
        cout<<minHeap.pop(); // Popping From Min Heap
        if(minHeap.size()>0) cout<<",";
    }
    cout<<"]\n";
    cout<<"Max Heap of int  : ";
    cout<<"[";
    while(!maxHeap.empty()) {
        cout<<maxHeap.pop(); // Popping From Max Heap
        if(maxHeap.size()>0) cout<<",";
    }
    cout<<"]\n";
    // Min & Max Heaps of Node*
    vector<Node*> nodes;
    for(int val:vals) nodes.push_back(new Node(val));   
    Heap<Node*,MinCompare> minHeapNode(nodes); // Building Custom Node Min Heap From Vector
    Heap<Node*,MaxCompare> maxHeapNode(nodes); // Building Custom Node Max Heap From Vector
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
    for(Node*& node:nodes) delete node; // Memory Cleanup
    return 0;
}
#include<iostream>
#include<vector>
#include"minheap.h"
using namespace std;

int main() {
    MinHeap<int> obj({3,4,5,1,2});
    cout<<'[';
    while(!obj.empty()) {
        cout<<obj.pop();
        if(obj.size()>0) cout<<',';
    }
    cout<<']';
    return 0;
}
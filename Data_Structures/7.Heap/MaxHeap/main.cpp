#include<iostream>
#include<vector>
#include"maxheap.h"
using namespace std;

int main() {
    MaxHeap<int> obj({3,4,5,1,2});
    cout<<'[';
    while(!obj.empty()) {
        cout<<obj.pop();
        if(obj.size()>0) cout<<',';
    }
    cout<<']';
    return 0;
}
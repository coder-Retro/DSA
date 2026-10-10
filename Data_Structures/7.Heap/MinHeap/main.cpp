#include<iostream>
#include<vector>
#include"minheap.h"
using namespace std;

int main() {
    MinHeap<int> obj;
    vector<int> vals={3,4,5,1,2};
    for(int i=0;i<vals.size();i++) obj.push(vals[i]);
    cout<<'[';
    while(!obj.empty()) {
        cout<<obj.pop();
        if(obj.size()>0) cout<<',';
    }
    cout<<']';
    return 0;
}
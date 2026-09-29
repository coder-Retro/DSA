#include<iostream>
#include"queue.h"
using namespace std;
int main() {
    int size=5;
    Queue<int> q(size);
    for(int i=1;i<=size;i++) {
        q.push(i);
        cout<<i<<" is inserted\n";
    }
    while(!q.empty()) {
        cout<<q.Front()<<" ";
        q.pop();
    }
    return 0;
}
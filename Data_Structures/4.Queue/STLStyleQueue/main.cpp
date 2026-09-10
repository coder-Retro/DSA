#include<iostream>
#include"queue.h"
using namespace std;
int main()
{
    Queue<int> q;
    for(int i=1;i<=5;i++) {
        q.push(i);
        cout<<i<<" is inserted\n";
    }
    while(!q.empty()) {
        cout<<q.front()<<" is removed\n";
        q.pop();
    }
    return 0;
}
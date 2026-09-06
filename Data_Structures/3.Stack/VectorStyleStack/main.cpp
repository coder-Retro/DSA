#include<iostream>
#include"stack.h"
using namespace std;
int main() {
    Stack<int> s;
    for(int i=1;i<=5;i++) {
        s.push(i);
        cout<<i<<" is inserted\n";
    }
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
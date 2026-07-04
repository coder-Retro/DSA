#include<iostream>
#include"stack"
using namespace std;
int main()
{
    stack s;
    for(int i=1;i<=5;i++)
    {
        s.push(i);
        cout<<i<<" is inserted\n";
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
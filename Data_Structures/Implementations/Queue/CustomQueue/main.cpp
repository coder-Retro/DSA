#include<iostream>
#include"queue"
using namespace std;
int main()
{
    queue q;
    for(int i=1;i<=5;i++)
    {
        q.enqueue(i);
        cout<<i<<" is inserted\n";
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.dequeue();
    }
    return 0;
}
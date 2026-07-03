#include<iostream>
#include"deque"
using namespace std;
int main()
{
    deque dq;
    // Pushing
    for(int i=1;i<=6;i++)
    {
        if(i<4) { dq.push_back(i);  cout<<i<<" inserted from back\n"; }
        else    { dq.push_front(i); cout<<i<<" inserted from front\n"; }
    }
    // Insertion Checks
    for(int i=1;i<=6;i++)
    {
        if(i<4) { cout<<dq.back()<<" removed from back\n"; dq.pop_back(); }
        else    { cout<<dq.front()<<" removed from front\n"; dq.pop_front(); }
    }
    // Empty Check
    cout<<"Empty Check: "<<dq.empty();
    return 0;
}
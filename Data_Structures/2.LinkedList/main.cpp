#include<iostream>
#include"list"
using namespace std;
// Main Function
int main()
{
    list<int> ll;
    cout<<ll.empty();
    cout<<'\n';
    ll.putFront(3);
    ll.putFront(2);
    ll.putFront(1);
    ll.putBack(4);
    ll.putBack(5);
    ll.putBack(6);
    ll.insertNode(7,3);
    ll.deleteNode(5);
    cout<<ll.searchNode(7);
    cout<<'\n';
    cout<<ll.empty();
    return 0;
}
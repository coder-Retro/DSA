#include<iostream>
#include<vector>
#include"list.h"
using namespace std;
// Helper Function


// Main Function
int main()
{
    CirclyLinkedList<int> ll;
    // Pushing Values
    ll.push_front(0);
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    // Original List
    vector<int> vals=ll.values();
    for(int i:vals) cout<<i<<" ";
    cout<<'\n';
    // Reversed List
    ll.reverse();
    vector<int> revs=ll.values();
    for(int i:revs) cout<<i<<" ";
    cout<<'\n';
    // Value at [i]
    cout<<"ll[3]: "<<ll[3]<<'\n';
    // Contains Value
    cout<<"ll.contains(4): "<<boolalpha<<ll.contains(4)<<'\n';
    cout<<"ll.contains(40): "<<boolalpha<<ll.contains(40)<<'\n';
    cout<<"ll.find(4): "<<ll.find(4)<<'\n';
    cout<<"ll.find(40): "<<ll.find(40)<<'\n';
    // Popping Values
    while(!ll.empty()) ll.pop_front();
    return 0;
}
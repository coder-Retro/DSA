#include<iostream>
#include<vector>
using namespace std;
/*
Vectors are basically re-sizable dynamic arrays that can increase
their size on runtime whenever a new element is pushed into them.
Majority of Leetcode problems require use of vectors rather than
arrays which have a fixed size and cant be changed on runtime.
Vector functions :
.size();             gives size of vector
.push_back(value);   adds a value to back of vector
.pop_back();         removes a value from back of vector
.front();            gives the value at front of vector
.back();             gives the value at back of vector
.at(index);          gives the value at index i, same as vec[i]
*/
int main()
{
    // Declaration:
    vector<int> v;
    // Size Function :
    cout<<v.size()<<'\n';
    // Push Back Function :
    v.push_back(1); // adds element to the back of vector
    v.push_back(2);
    v.push_back(3);
    // Size Function:
    cout<<v.size()<<'\n'; // gives the size of vector
    // For Each Loop :
    for(int value:v) cout<<value<<" ";
    cout<<'\n';
    // Pop Back Function :
    v.pop_back(); // removes element from back of vector
    // Back Function :
    cout<<v.back()<<'\n'; // gives back element of vector
    // Front Function :
    cout<<v.front()<<'\n'; // gives front element of vector
    // at Function :
    for(int i=0;i<(int)v.size();i++)
        cout<<v.at(i)<<" "; // same as v[i];
    return 0;
}
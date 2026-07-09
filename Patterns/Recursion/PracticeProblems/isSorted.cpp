#include<iostream>
#include<vector>
using namespace std;

/*
Problem Statement:
You are required to write a boolean function
which takes a "const vector<int>" passed by
reference, and the size of vector<int>. The
function should return true if the vector is
sorted in increasing oreder or false if it's
not sorted in increasing order.

Constraints:
1. You are not allowed to use built-in loops.
2. You function must achieve this using recursion.
*/

// Recursion Class
class Recursion {
public:
    bool isSorted(const vector<int>& num,int n) {
        // Your Code Here
    }
};

// Main Function
int main() {
    Recursion r;
    vector<int> num={1,2,3,4,5,6,7,8,9,10};
    if(r.isSorted(num,num.size())) cout<<"Sorted";
    else                           cout<<"Unsorted";
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
Problem Statement:
You need to write a recursive function that
takes a "const vector<int>" passed by reference,
the first index of vector, the last index of vector
and another "int target". Then it should perform
recursive binary search on that vector and return
the index of target (if it exists), otherwise -1
should be returned.

Constraints:
1. You are not allowed to use any built-in loops.
2. Your function must achieve this using recursion.
*/

// Recursion Class
class Recursion {
public:
    int BinarySearch(const vector<int>& vec,int start,int end,int target) {
        // Your Code Here
    }
};

// Main Function
int main() {
    Recursion r;
    vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    int target=5;
    cout<<target<<" found at index : ";
    cout<<r.BinarySearch(vec,0,vec.size()-1,target);
    return 0;
}
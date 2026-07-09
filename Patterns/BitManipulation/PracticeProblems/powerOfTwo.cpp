#include<iostream>
using namespace std;

/*
Problem Statement:
Your are required to write a function that takes
an "int n" in arguments and returns a boolean to
determine if the given number is a power of two.
If it is a power of two, true shall be returned,
if it is not a power of two then false shall be
returned.

Constraints:
1. You are not allowed to use built-in loops.
2. You are not allowed to use recursion.
3. You can only use BitWise and logical operators.
4. Your function should be O(1) in Time & Space.
*/

// Bit Manipulation Class
class BitManipulation {
public:
    bool isPowerOfTwo(int n) {
        // Your Code Here
    }
};

// Main Function
int main() {
    BitManipulation obj;
    int n;
    cout<<"Enter a number: "; cin>>n;
    if(obj.isPowerOfTwo(n))
        cout<<n<<" is in powers of 2";
    else
        cout<<n<<" is not in powers of 2";
    return 0;
}
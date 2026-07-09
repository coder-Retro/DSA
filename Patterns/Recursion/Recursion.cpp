#include<iostream>
using namespace std;

/*
Recursion:
Recursion is the phenomenon where a function calls itself.
The calls keep on happening until a certain case known as
"Base Case" is reached. From this point the function goes
back to its calling location and so on, this return cycle
is called "Back Tracking". Recursion is used mostly where 
we want to do something over and over again like looping.
So yeah recursion is an alternative of looping. Recursion
is used in cases where we want utilize the infamous trick
known as the "Divide & Conquer" approach.

Note:
Recursion is mostly used in Data Structures like Tree and
Graph because it is easy to understand recusion logics in
in these instead of trying to create the same effect with
looping. Commonly used recursive techniques are traversal
methods in Binary Trees, these are:
1. preOrder
2. inOrder
3. postOrder
*/

// Recursive Function
int nFactorial(int n)
{
    if(n==1) return n;
    return n*nFactorial(n-1);
}
// Main Function
int main()
{
    cout<<nFactorial(4);
    return 0;
}
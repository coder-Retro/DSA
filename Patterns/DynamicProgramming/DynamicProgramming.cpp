#include<iostream>
using namespace std;

/*
Dynamic Programming:
Dynamic Programming (DP in short), is an advanced pattern which
aims to use its previously calculated values to find the next
value. It works by starting from the base case of a problem and
walking forward from that point towards the actual answer. Let's
say we want to find the nth fibonacci term. DP starts from n=0
and works by computing n3=n1+n2. When loop reaches the nth run,
it returns the current n2 which now holds the last computed n3.
There are three ways in  which DP is implemented:
1. Top-Down (Memoization) DP
2. Bottom-Up (Tabulation) DP
3. Space Optimized Bottom-Up DP
The function given below is an example of the third case. It
uses iteration rather than recursion to achieve O(n) TC, and
it uses three rolling variables instead of an array to achieve
O(1) SC. Hence it uses minimal time and minimal space. DP is
the most advanced problem solving pattern and also the most 
difficult pattern to get a good grasp on. But it is also the
strongest pattern which is capable of converting slow TCs of
O(2ⁿ) to O(n) and SCs of O(n) to O(1).
*/

// Dynamic Programming Function
long long nth_fibonacci(int n) {
    if(n<2) return n;
    long long n1=0,n2=1;
    for(int i=2;i<=n;i++) {
        long long n3=n1+n2;
        n1=n2;
        n2=n3;
    }
    return n2;
}
#include<iostream>
#include<unordered_map>
using namespace std;

/*
Memoization:
Memoization is a pattern used to stop our algorithm from
calculating results that it has calculated previously. A
memoized algorithm aims to do less computations by keeping
track of its previous computations. If it hits a case that
is present in the history of its computations, it simply
returns the precomputed result of that case from its log,
rather than calculating it again. Memoization is mostly
used in recursive cases. A good example of memoization is
finding the nth fibonacci term using recursion. It works
by using an STL container like vector or unordered_map to
keep logs of its history. Vector is preferred for small
fixed ranges and hashmaps for variable/larger ranges.
*/

// Memoization Function
unordered_map<int,int> cache;
int nth_fibonacci(int n) {
    if(n<2) return n;
    if(cache.find(n)!=cache.end()) return cache[n];
    int result=nth_fibonacci(n-1)+nth_fibonacci(n-2);
    cache[n]=result;
    return result;
}
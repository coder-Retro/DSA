#include<iostream>
using namespace std;

/*
Approach: Coprime Consecutive Integers
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};

/*
Explanation: 
Sum of First n odd  = n²
Sum of First n even = n(n+1)
gcd(n²,n(n+1)) = n(gcd(n,n+1))
n(gcd(n,n+1))  = n(1)  "Since gcd of consecutive ints = 1"
n(1) = n
*/

int main() {
    Solution obj;
    int n=5;
    cout<<obj.gcdOfOddEvenSums(n);
    return n;
}
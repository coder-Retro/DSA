#include<iostream>
using namespace std;

/*
Approach: Modulo Digit Extraction
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int smallestNumber(int n,int t) {
        while(n%10) {
            int product=1;
            int current=n;
            while(current) {
                product*=(current%10);
                current/=10;
            }
            if(!(product%t)) break;
            n++;
        }
        return n;
    }
};

/*
Explanation:
The code itself is quite self explanatory but this explanation
is aimed to show how the TC is O(1) despite the two loops that
are running in this algo. We know that as soon as "n" becomes
a multiple of 10, its digits' product will always be "0" hence
it will always be divisible by "t", so this means that in the
worst case, outer loop will run 9 times where 9 is a constant.
Therefore outer loop is O(1). Now the inner loop, this runs as
many times as the number of digits in current "n". But here is
the catch, leetcode constraints say: 1 <= n <= 100. This shows
that "n" can have maximum of 3 digits as it is capped at 100.
So in the worst case, the inner loop will run 3 times, where 3
is again a constant. Therefore inner loop is also O(1). Hence
outer loop "worst case 9 iterations: O(1)" and the inner loop
"worst case 3 iterations: O(1)" will together form a TC: O(1).
*/

int main() {
    Solution obj;
    int n=15;
    int t=3;
    cout<<obj.smallestNumber(n,t);
    return 0;
}
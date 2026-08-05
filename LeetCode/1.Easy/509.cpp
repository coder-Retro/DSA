#include<iostream>
using namespace std;

/*
Approach: Dynamic Programming / Tabulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int prev=0,curr=1;
        int next;
        for(int i=2;i<=n;i++) {
            next=prev+curr;
            prev=curr;
            curr=next;
        }
        return curr;
    }
};
int main() {
    Solution s;
    cout<<s.fib(5);
    return 0;
}
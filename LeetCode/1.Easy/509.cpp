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
        for(int i=2;i<=n;i++) {
            int next=prev+curr;
            prev=curr;
            curr=next;
        }
        return curr;
    }
};

int main() {
    Solution obj;
    cout<<obj.fib(5);
    return 0;
}
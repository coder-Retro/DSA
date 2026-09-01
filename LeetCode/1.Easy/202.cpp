#include<iostream>
using namespace std;

/*
Approach: Floyd's Cycle Detection
TC: O(log n)
SC: O(1)
*/

class Solution {
    int next(int n) {
        int sum=0;
        while(n) {
            int digit=n%10;
            sum+=(digit*digit);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow=n;
        int fast=next(n);
        while(fast!=1 && slow!=fast) {
            slow=next(slow);
            fast=next(next(fast));
        }
        return fast==1;
    }
};

int main() {
    Solution obj;
    int n=7;
    cout<<(obj.isHappy(n)?"true":"false");
    return 0;
}
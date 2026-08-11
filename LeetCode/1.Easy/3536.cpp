#include<iostream>
using namespace std;

/*
Approach: Greedy / Max Tracking
TC: O(log n)
SC: O(1)
*/

class Solution {
public:
    int maxProduct(int n) {
        int d1=0,d2=0;
        while(n) {
            int d=n%10;
            if     (d>=d1) { d2=d1; d1=d; }
            else if(d>d2)  { d2=d; }
            n/=10;
        }
        return d1*d2;
    }
};

int main() {
    Solution obj;
    int n=124;
    cout<<obj.maxProduct(n);
    return 0;
}
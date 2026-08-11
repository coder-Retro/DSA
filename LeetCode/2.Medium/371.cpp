#include<iostream>
using namespace std;

/*
Approach: Bit Manipulation / Carry Tracking
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int c=a&b;
            a^=b;
            b=c<<1;
        }
        return a;
    }
};

int main() {
    Solution obj;
    int a=2;
    int b=3;
    cout<<obj.getSum(a,b);
    return 0;
}
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
int main() {
    Solution obj;
    int n=15;
    int t=3;
    cout<<obj.smallestNumber(n,t);
    return 0;
}
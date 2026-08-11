#include<iostream>
using namespace std;

/*
Approach: Iterative Product
TC: O(log n)
SC: O(1)
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        long pow=1;
        while(pow<n) pow*=4;
        return (pow==n);
    }
};

int main() {
    Solution obj;
    int n=16;
    (obj.isPowerOfFour(n))?cout<<"true":cout<<"false";
    return 0;
}
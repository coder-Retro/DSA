#include<iostream>
using namespace std;

/*
Approach: Bit Manipulation
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && !(n&(n-1)); 
    }
};

int main() {
    Solution obj;
    int n=3;
    (obj.isPowerOfTwo(n))?cout<<"true":cout<<"false";
    return 0;
}
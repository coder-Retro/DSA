#include<iostream>
using namespace std;

/*
Approach: Constant Divisibility
TC: O(log n)
SC: O(1)
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1162261467 is 3^19 max-int in power of 3
        return (n>0) && !(1162261467 % n);
    }
};

int main() {
    Solution obj;
    int n=1;
    (obj.isPowerOfThree(n))?cout<<"true":cout<<"false";
    return 0;
}
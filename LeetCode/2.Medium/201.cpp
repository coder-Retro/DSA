#include<iostream>
using namespace std;

/*
Approach: Bit Manipulation
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shifts=0;
        while(left!=right) {
            left>>=1;
            right>>=1;
            shifts++;
        }
        return left<<shifts;
    }
};

int main() {
    Solution obj;
    int left=5;
    int right=7;
    cout<<obj.rangeBitwiseAnd(left,right);
    return 0;
}
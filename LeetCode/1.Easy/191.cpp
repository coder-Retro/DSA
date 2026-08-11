#include<iostream>
using namespace std;

/*
Approach: Brian Kernighan’s Algo / Bit Manipulation
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n) {
            n&=(n-1);
            count++;
        }
        return count;
    }
};

int main() {
    Solution obj;
    int n=11;
    cout<<obj.hammingWeight(n);
    return 0;
}
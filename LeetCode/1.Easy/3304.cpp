#include<iostream>
#include<string>
using namespace std;

/*
Approach: Brian Kernighan's Algo / Bit Manipulation
TC: O(log k), k = number of set bits in kth character
SC: O(1)
*/

class Solution {
public:
    char kthCharacter(int k) {
        int bits=0;
        k--;
        while(k) { k&=(k-1); bits++; }
        return 'a'+bits;
    }
};
int main() {
    Solution obj;
    int k=10;
    cout<<obj.kthCharacter(k);
    return 0;
}
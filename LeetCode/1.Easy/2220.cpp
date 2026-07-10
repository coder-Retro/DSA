#include<iostream>
using namespace std;

/*
Approach: BrianKernighan's Algo / Bit Manipulation
TC: O(k), k = number of set bits in start^goal
SC: O(1)
*/

class Solution {
public:
    int minBitFlips(int start,int goal) {
        int count=0;
        start^=goal;
        while(start) {
            start&=(start-1);
            count++;
        }
        return count;
    }
};
int main() {
    Solution s;
    int start=10;
    int goal=7;
    cout<<s.minBitFlips(start,goal);
    return 0;
}
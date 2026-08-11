#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Bit Manipulation
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans=0;
        for(size_t i=0;i<32;i++) {
            ans<<=1;
            ans|=(n&1);
            n>>=1;
        }
        return ans;
    }
};

int main() {
    Solution obj;
    cout<<obj.reverseBits(43261596)<<'\n';
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Dynamic Programming / Bit Manipulation / BrianKernighan's Algo
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<ans.size();i++)
            ans[i]=ans[i&(i-1)]+1;
        return ans;
    }
};
int main() {
    Solution s;
    int n=10;
    vector<int> ans=s.countBits(n);
    for(int i:ans) cout<<i<<" ";
    return 0;
}
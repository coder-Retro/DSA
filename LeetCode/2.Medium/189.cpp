#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: In-Place Tripple Reversal
TC: O(n)
SC: O(1)
*/

class Solution {
    void reverseBetween(vector<int>& v,int l,int r) {
        while(l<r) swap(v[l++],v[r--]);
    }
public:
    void rotate(vector<int>& nums,int k) {
        int n=nums.size();
        if(!n || !k) return;
        k%=n;
        int i,j;
        reverseBetween(nums,0,n-1);
        reverseBetween(nums,0,k-1);
        reverseBetween(nums,k,n-1);
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,2,3,4,5};
    int k=2;
    obj.rotate(nums,k);
    for(int i:nums) cout<<i<<" ";
    return 0;
}
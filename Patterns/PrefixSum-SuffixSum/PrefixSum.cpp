#include<iostream>
#include<vector>
using namespace std;

/*
Prefix Sum:
It is one of the most basic DSA pattern which is used
when we need the sum of all elements of an array upto
a certain index of it, so we use this pattern to make
the sum array once and then just use it as many times
as we need. This saves us the time to calculate these
sum over and over again. Time complexity of this algo
is O(n) and Space complexity is O(n).
*/

// Prefix Sum Function
vector<int> prefixSum(vector<int>& arr) {
    vector<int> preSum(arr.begin(),arr.end());
    for(int i=1;i<arr.size();i++) preSum[i]+=preSum[i-1];
    return preSum;
}
// Main Function
int main() {
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    vector<int> preSum=prefixSum(arr);
    for(int i:preSum) cout<<i<<" ";
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
Suffix Sum:
It's the opposite of prefix sum pattern which is used
when we need the sum of all elements of an array from
ith index to the last index of array, so we use this
pattern to make the sum array once and then just use
it as many times as we need. This saves us the time to
calculate these sum over and over again. The overall
Time complexity of this algo is O(n) and the Overall
Space complexity is O(n).
*/

// Suffix Sum Function
vector<int> suffixSum(vector<int>& arr) {
    vector<int> sufSum(arr.begin(),arr.end());
    for(int i=arr.size()-2;i>=0;i--) sufSum[i]+=sufSum[i+1];
    return sufSum;
}
// Main Function
int main() {
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    vector<int> sufSum=suffixSum(arr);
    for(int i:sufSum) cout<<i<<" ";
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
Sliding Window:
This is a DSA pattern that is used when dealing with
subarrays of a certain size inside a larger array to
calculate different values withing the bounds of the
subarray. It uses two pointers in it, one for marking
the left bound of subarray, and another for marking 
the right bound of the array. The Time complexity of
this algo is O(n) and the Space complexity of is O(1)
because it only declares two pointers regardless of 
the input size.
*/

// Sliding Window Function
int maxSubArraySumOfSizeK(vector<int>& arr,int k) {
    if(k>arr.size()) return 0;
    int left=0;
    int right=0;
    int currSum=0;
    while(right<k) currSum+=arr[right++];
    int maxSum=currSum;
    while(right<arr.size()) {
        currSum-=arr[left++];
        currSum+=arr[right++];
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}
// Main Function
int main() {
    vector<int> arr={1,1,1,3,3,3,2,2,2};
    int window=3;
    cout<<maxSubArraySumOfSizeK(arr,window);
    return 0;
}
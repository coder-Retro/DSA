#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
Use Case:
Kadene's algorithm is used to find the max
Sub array sum in an array. It works by the
successive addition until sum falls below
0, then it resets sum to 0. It compares the
value of sum to maxSum detected till now and
constantly updates it if sum gets larger
than maxSum.
*/

/*
Approach: Dynamic Programming
TC: O(n)
SC: O(1)
*/

class Kadane {
public:
    int maxSubArraySum(vector<int>& nums) {
        int curr=0;
        int maxSum=INT_MIN;
        for(int i:nums) {
            curr+=i;
            maxSum=max(maxSum,curr);
            if(curr<0) curr=0;
        }
        return maxSum;
    }
};

int main() {
    Kadane obj;
    vector<int> nums={1,-2,3,4,5,-6,7,-10};
    cout<<obj.maxSubArraySum(nums); 
    return 0;
}
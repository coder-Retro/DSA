#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Sorting / Linear Reduction
TC: O(n log n)
SC: O(1)
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0]=1;
        for(int i=1;i<arr.size();i++) arr[i]=min(arr[i],arr[i-1]+1);
        return arr.back();
    }
};

int main() {
    Solution obj;
    vector<int> arr={1,2,3,4,5};
    cout<<obj.maximumElementAfterDecrementingAndRearranging(arr);
    return 0;
}
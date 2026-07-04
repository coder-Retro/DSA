#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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
    Solution s;
    vector<int> arr={1,2,3,4,5};
    cout<<s.maximumElementAfterDecrementingAndRearranging(arr);
    return 0;
}
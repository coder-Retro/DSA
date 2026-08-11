#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
Approach: Min Tracking
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans=-1;
        int minValue=INT_MAX;
        for(int i=0;i<capacity.size();i++) {
            if(capacity[i]<minValue && capacity[i]>=itemSize) {
                ans=i;
                minValue=capacity[i];
            }   
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> capacity={3,5,4,3};
    int itemSize=2;
    cout<<obj.minimumIndex(capacity, itemSize);
    return 0;
}
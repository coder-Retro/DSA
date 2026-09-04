#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Prefix-Max / Suffix-Min
TC: O(n)
SC: O(n)
*/

class Solution {
    vector<int> preMax(const vector<int>& v) {
        vector<int> maxes(v.size(),0);
        int n=v.size();
        maxes[0]=v[0];
        int maxVal=v[0];
        for(int i=1;i<n;i++) {
            maxVal=max(maxVal,v[i]);
            maxes[i]=maxVal;
        }
        return maxes;
    }
    vector<int> posMin(const vector<int>& v) {
        vector<int> mines(v.size(),0);
        int n=v.size();
        mines[n-1]=v[n-1];
        int minVal=v[n-1];
        for(int i=n-2;i>=0;i--) {
            minVal=min(minVal,v[i]);
            mines[i]=minVal;
        }
        return mines;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxes=preMax(nums);
        vector<int> mines=posMin(nums);
        for(int i=0;i<nums.size();i++)
            if(maxes[i]-mines[i]<=k) return i;
        return -1;
    }
};

int main() {
    Solution obj;
    vector<int> nums={5,0,1,4};
    int k=3;
    cout<<obj.firstStableIndex(nums,k);
    return 0;
}
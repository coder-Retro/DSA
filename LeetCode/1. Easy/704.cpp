#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int BinSearch(vector<int>& nums,int s,int e,int t)
    {
        if(s>e) return -1;
        int mid=s+(e-s)/2;
        if(nums[mid]==t)     return mid;
        else if(nums[mid]<t) return BinSearch(nums,mid+1,e,t);
        else                 return BinSearch(nums,s,mid-1,t);
    }
public:
    int search(vector<int>& nums, int target) {
        return BinSearch(nums,0,nums.size()-1,target);
    }
};
int main()
{
    Solution s;
    vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    int target=0;
    int index=s.search(vec,target);
    if(index<0)
        cout<<target<<" not found in array.";
    else
        cout<<target<<" found at index : "<<index;
    return 0;
}
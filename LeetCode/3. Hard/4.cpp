#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        double median;
        int i=0,j=0;
        while(i<nums1.size() || j<nums2.size())
            if(j==nums2.size() || (i<nums1.size() && nums1[i]<nums2[j]))
                nums3.push_back(nums1[i++]);
            else
                nums3.push_back(nums2[j++]);
        int size=nums3.size();
        if(size%2!=0)
            median=nums3[size/2];
        else
            median=(nums3[size/2-1]+nums3[size/2])/2.0;
        return median;
    }
};
int main()
{
    Solution s;
    vector<int> nums1={1,3},nums2={2};
    cout<<s.findMedianSortedArrays(nums1,nums2);
    return 0;
}
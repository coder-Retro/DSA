#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Use Case:
Dutch National Flag algorithm is used to sort an array consisting
of upto 3 distinct elements in linear time using three pointers in
a single loop. However, this algorithm can only be used when the
number of distinct elements is 3, if it is above 3, then this
algorithm is in applicable. It works by using setting 3 bounds,
one for each element.
*/

/*
Approach: Three Pointers
TC: O(n)
SC: O(1)
*/

class DutchNationalFlag {
public:
    void sort(vector<int>& nums) {
        int l=0,m=0,h=nums.size()-1;
        while(m<=h)
            if     (nums[m]==0) swap(nums[m++],nums[l++]);
            else if(nums[m]==1) m++;
            else                swap(nums[m],nums[h--]);
    }
};
int main() {
    DutchNationalFlag obj;
    vector<int> nums={0,1,1,2,0,2,1,2,0};
    obj.sort(nums);
    for(int i:nums) cout<<i<<" ";
    return 0;
}
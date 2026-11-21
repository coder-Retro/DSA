#include<iostream>
#include<vector>
using namespace std;

/*
Use Case:
Merge sort algorithm is used to sort the dataset
in linearithmic time, it is one of the optimized,
fast and efficient sorting algorithms. It works
by dividing the dataset into halves recursively
until it consists of only a single element, then
it uses two pointer pattern to build it back up
in sorted order using a temporary allocated space.
*/

/*
Approach: Recursion / Divide And Conquer
TC: O(n log n)
SC: O(n)
*/

class Solution {
private:
    void merge(vector<int>& v,int start,int mid,int end) {
        vector<int> merged;
        int left=start,right=mid+1;
        while(left<=mid && right<=end) {
            if(v[left]<v[right]) merged.push_back(v[left++]);
            else                 merged.push_back(v[right++]);
        }
        while(left<=mid)  merged.push_back(v[left++]);
        while(right<=end) merged.push_back(v[right++]);
        for(int i=0;i<(int)merged.size();i++) v[start+i]=merged[i];
    }
    void mergeSort(vector<int>& v,int start,int end) {
        if(start<end) {
            int mid=start+(end-start)/2;
            mergeSort(v,start,mid);
            mergeSort(v,mid+1,end);
            merge(v,start,mid,end);
        }
    }
public:
    void mergeSort(vector<int>& v) { mergeSort(v,0,v.size()-1); }
};

int main() {
    // Objects
    Solution s;
    vector<int> nums[3]={{2,0,-4,5,-1,3},{4,5,1,2},{13,4,51,2,60,7,8,-33,102,-200}};
    // Original Vector
    for(vector<int>& num:nums) {
        cout<<"Original Vector: ";
        for(int i:num) cout<<i<<" ";
        // Applying Merge Sort
        s.mergeSort(num);
        // Sorted Vector
        cout<<"\nSorted Vector  : ";
        for(int i:num) cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}
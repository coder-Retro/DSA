#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int s=0,e=matrix.size()-1,row=-1,mid;
        while(s<=e)
        {
            row=s+(e-s)/2;
            if(matrix[row][0]<=target && matrix[row][matrix[row].size()-1]>=target){ break; }
            if(matrix[row][matrix[row].size()-1]<target) s=row+1;
            else e=row-1; 
        }
        if(row==-1 || matrix[row][0]>target || matrix[row][matrix[row].size()-1]<target) return false;
        s=0,e=matrix[row].size()-1;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(matrix[row][mid]==target) return true;
            if(matrix[row][mid]<target) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> mat={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    if(s.searchMatrix(mat,target))  cout<<"Target Exists";
    else cout<<"Target Doesn't Exist";
    return 0;
}
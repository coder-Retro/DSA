#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: 
TC: O(m*n), m and n are rows and columns of grid
SC: O(m*n), m and n are rows and columns of grid
*/

class Solution {
private:
    void reverse(vector<int>& flat,int l,int r) {
        while(l<r) swap(flat[l++],flat[r--]);
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid ,int k) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int> flat(row*col);
        for(int i=0,k=0;i<row;i++)
            for(int j=0;j<col;j++)
                flat[k++]=grid[i][j];
        k%=flat.size();
        int n=flat.size();
        reverse(flat,0,n-1);
        reverse(flat,0,k-1);
        reverse(flat,k,n-1);
        for(int i=0,k=0;i<row;i++)
            for(int j=0;j<col;j++)
                grid[i][j]=flat[k++];
        return grid;
    }
};
int main() {
    Solution obj;
    vector<vector<int>> grid={{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
    int k=4;
    grid=obj.shiftGrid(grid,k);
    for(vector<int>& v:grid) {
        for(int i:v) cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}
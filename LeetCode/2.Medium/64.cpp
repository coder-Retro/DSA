#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Dynamic Programming
TC: O(m*n), m and n are rows and columns 
SC: O(1)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        for(int i=1;i<r;i++) grid[i][0]+=grid[i-1][0];
        for(int i=1;i<c;i++) grid[0][i]+=grid[0][i-1];
        for(int i=1;i<r;i++)
            for(int j=1;j<c;j++)
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
        return grid[r-1][c-1];
    }
};

int main() {
    Solution obj;
    vector<vector<vector<int>>> grids={
        {{1,3,1},{1,5,1},{4,2,1}},
        {{1,2,3},{4,5,6}}
    };
    for(auto& grid:grids) cout<<obj.minPathSum(grid)<<'\n';
    return 0;
}
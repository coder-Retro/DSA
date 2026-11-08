#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Simulation
TC: O(m*n*(m+n)), m and n are rows and columns
SC: O(1)
*/

class Solution {
    bool isConnected(vector<vector<int>>& grid,int r,int c) {
        // Check Row Left
        for(int i=c-1;i>=0;i--) if(grid[r][i]) return true;
        // Check Row Right
        for(int i=c+1;i<grid[0].size();i++) if(grid[r][i]) return true;
        // Check Column Top
        for(int i=r-1;i>=0;i--) if(grid[i][c]) return true;
        // Check Columm Bottom
        for(int i=r+1;i<grid.size();i++) if(grid[i][c]) return true;
        // Isolated Server
        return false;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] && isConnected(grid,i,j)) count++;
            }
        }
        return count;
    }
};

int main() {
    Solution obj;
    vector<vector<vector<int>>> grids = {
        {{1,0},{0,1}},
        {{1,0},{1,1}}
    };
    for(auto& grid:grids) cout<<obj.countServers(grid)<<'\n';
    return 0;
}
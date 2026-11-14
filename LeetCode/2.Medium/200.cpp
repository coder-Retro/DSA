#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

/*
Approach: BFS / Queue
TC: O(m*n), m and n are rows and columns
SC: O(m*n), m and n are rows and columns
*/

class Solution {
    void bfs(vector<vector<char>>& grid,int m,int n,int r,int c) {
        queue<pair<int,int>> q;
        grid[r][c]='0';
        q.push({r,c});
        while(!q.empty()) {
            auto [i,j]=q.front();
            q.pop();
            if(i>0 && grid[i-1][j]=='1')   { grid[i-1][j]='0'; q.push({i-1,j}); }
            if(j>0 && grid[i][j-1]=='1')   { grid[i][j-1]='0'; q.push({i,j-1}); }
            if(i+1<m && grid[i+1][j]=='1') { grid[i+1][j]='0'; q.push({i+1,j}); }
            if(j+1<n && grid[i][j+1]=='1') { grid[i][j+1]='0'; q.push({i,j+1}); }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    count++;
                    bfs(grid,m,n,i,j);
                }
            }
        }
        return count;
    }
};

int main() {
    Solution obj;
    vector<vector<vector<char>>> grids={
        {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
        },
        {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
        }
    };
    for(auto& grid:grids) cout<<obj.numIslands(grid)<<'\n';
    return 0;
}
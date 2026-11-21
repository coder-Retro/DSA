#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

/*
Approach: BFS / Queue
TC: O()
SC: O()
*/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size();
        int r=entrance[0],c=entrance[1];
        queue<pair<int,int>> q;
        maze[r][c]='+';
        q.push({r,c});
        int steps=0;
        while(!q.empty()) {
            int size=q.size();
            while(size--) {
                auto [i,j]=q.front();
                q.pop();
                if(!(i==r && j==c) && (i==0 || j==0 || i==m-1 || j==n-1))
                    return steps;
                if(i>0 && maze[i-1][j]=='.')   { maze[i-1][j]='+'; q.push({i-1,j}); }
                if(j>0 && maze[i][j-1]=='.')   { maze[i][j-1]='+'; q.push({i,j-1}); }
                if(i+1<m && maze[i+1][j]=='.') { maze[i+1][j]='+'; q.push({i+1,j}); }
                if(j+1<n && maze[i][j+1]=='.') { maze[i][j+1]='+'; q.push({i,j+1}); }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> entrance={
        {1,2},
        {1,0},
        {0,0}
    };
    vector<vector<vector<char>>> entrances={
        {
            {'+','+','.','+'},
            {'.','.','.','+'},
            {'+','+','+','.'}
        },
        {
            {'+','+','+'},
            {'.','.','.'},
            {'+','+','+'}
        },
        {
            {'.','+'}
        }
    };
    for(int i=0;i<(int)entrance.size();i++)
        cout<<obj.nearestExit(entrances[i],entrance[i])<<'\n';
    return 0;
}
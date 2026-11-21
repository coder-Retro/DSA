#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Approach: BFS / Queue
TC: O(m*n), m and n are rows and columns
SC: O(min(m,n)), m and n are rows and columns
*/

class Solution {
    void bfs(vector<vector<char>>& board,int m,int n,int x,int y) {
        queue<pair<int,int>> q;
        q.push({x,y});
        board[x][y]='_';
        while(!q.empty()) {
            auto [i,j]=q.front();
            q.pop();
            if(i-1>=0 && board[i-1][j]=='O')
                { board[i-1][j]='_'; q.push({i-1,j}); }
            if(i+1<m && board[i+1][j]=='O')
                { board[i+1][j]='_'; q.push({i+1,j}); }
            if(j-1>=0 && board[i][j-1]=='O')
                { board[i][j-1]='_'; q.push({i,j-1}); }
            if(j+1<n && board[i][j+1]=='O')
                { board[i][j+1]='_'; q.push({i,j+1}); }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++) {
            if(board[i][0]=='O')   bfs(board,m,n,i,0);
            if(board[i][n-1]=='O') bfs(board,m,n,i,n-1);
        }
        for(int j=0;j<n;j++) {
            if(board[0][j]=='O')   bfs(board,m,n,0,j);
            if(board[m-1][j]=='O') bfs(board,m,n,m-1,j);
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]=='O')      board[i][j]='X';
                else if(board[i][j]=='_') board[i][j]='O';
            }
        }
    }
};

int main() {
    Solution obj;
    vector<vector<vector<char>>> boards = {
        {
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'}
        },
        {
            {'X'}
        }
    };
    for(auto& board:boards) {
        obj.solve(board);
        cout<<"[";
        for(int i=0;i<board.size();i++) {
            cout<<"[";
            for(int j=0;j<board[0].size();j++) {
                cout<<board[i][j];
                if(j<board[0].size()-1) cout<<",";
            }
            cout<<"]";
            if(i<board.size()-1) cout<<",";
        }
        cout<<"]\n";
    }
    return 0;
}
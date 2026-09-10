#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Approach: Recursion / DFS / Backtracking
TC: O(n!)
SC: O(n²)
*/

class Solution {
    bool isSafe(const vector<string>& board,int row,int col,int n) {
        // Checking Row
        for(int i=0;i<n;i++)
            if(board[row][i]=='Q') return false;
        // Checking Col
        for(int i=0;i<n;i++)
            if(board[i][col]=='Q') return false;
        // Checking Primary Diagonal
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
            if(board[i][j]=='Q') return false;
        // Checking Secondary Diagonal
        for(int i=row,j=col;i>=0&&j<n;i--,j++)
            if(board[i][j]=='Q') return false;
        // Position is Safe
        return true;
    }
    void dfs(vector<string>& board,int row,int n,int& ans) {
        if(row==n) {
            ans++;
            return;
        }
        for(int i=0;i<n;i++) {
            if(isSafe(board,row,i,n)) {
                board[row][i]='Q';
                dfs(board,row+1,n,ans);
                board[row][i]='.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        int ans=0;
        vector<string> board(n,string(n,'.'));
        dfs(board,0,n,ans);
        return ans;
    }
};

int main() {
    Solution obj;
    int n=4;
    cout<<obj.totalNQueens(n);
    return 0;
}
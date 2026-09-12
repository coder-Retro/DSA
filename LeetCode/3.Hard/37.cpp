#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Recursion / DFS / Backtracking
TC: O(1)
SC: O(1)
*/

class Solution {
    bool isSafe(const vector<vector<char>>& b,int r,int c,char ch) {
        // Checking Row and Col
        for(int i=0;i<9;i++) {
            if(i!=c && b[r][i]==ch) return false;
            if(i!=r && b[i][c]==ch) return false;
        }
        // Checking 3x3 Grid
        int gR=r/3*3;
        int gC=c/3*3;
        for(int i=gR;i<gR+3;i++) {
            for(int j=gC;j<gC+3;j++) {
                if(i==r && j==c) continue;
                if(b[i][j]==ch) return false;
            }
        }
        // Position is safe
        return true;
    }
    bool dfs(vector<vector<char>>& b,int r,int c) {
        if(r==9) return true;
        int nR=(c==8)?r+1:r;
        int nC=(c==8)?0:c+1;
        if(b[r][c]!='.') return dfs(b,nR,nC);
        for(char curr='1';curr<='9';curr++) {
            if(isSafe(b,r,c,curr)) {
                b[r][c]=curr;
                if(dfs(b,nR,nC)) return true;
                b[r][c]='.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
};

int main() {
    Solution obj;
    vector<vector<char>> board={
        {{'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}}
    };
    obj.solveSudoku(board);
    cout<<"Solved Sudoku Board:\n";
    for(vector<char>& v:board) {
        for(char c:v) cout<<c<<" ";
        cout<<'\n';
    }
    return 0;
}
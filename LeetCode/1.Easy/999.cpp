#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: Simulation / Grid Scanning
TC: O(1)
SC: O(1)
*/

class Solution {
    pair<int,int> findRook(vector<vector<char>>& board) {
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if(board[i][j]=='R') return {i,j};
        return {-1,-1};
    }
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans=0;
        // Finding Rook Position
        pair<int,int> rPos=findRook(board);
        // Checking Rook's Left
        for(int i=rPos.second-1;i>=0;i--) {
            if(board[rPos.first][i]=='B') break;
            if(board[rPos.first][i]=='p') { ans++; break; }
        }
        // Checking Rook's Right
        for(int i=rPos.second+1;i<8;i++) {
            if(board[rPos.first][i]=='B') break;
            if(board[rPos.first][i]=='p') { ans++; break; }
        }
        // Checking Rook's Up
        for(int i=rPos.first-1;i>=0;i--) {
            if(board[i][rPos.second]=='B') break;
            if(board[i][rPos.second]=='p') { ans++; break; }
        }
        // Checking Rook's Down
        for(int i=rPos.first+1;i<8;i++) {
            if(board[i][rPos.second]=='B') break;
            if(board[i][rPos.second]=='p') { ans++; break; }
        }
        // Returning Final Answer
        return ans;
    }
};

int main() {
    Solution obj;
    vector<vector<vector<char>>> boards = {
        {
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'.','.','.','R','.','.','.','p'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'}
        },
        {
            {'.','.','.','.','.','.','.','.'},
            {'.','p','p','p','p','p','.','.'},
            {'.','p','p','B','p','p','.','.'},
            {'.','p','B','R','B','p','.','.'},
            {'.','p','p','B','p','p','.','.'},
            {'.','p','p','p','p','p','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'}
        },
        {
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'p','p','.','R','.','p','B','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','B','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'}
        }
    };
    for(auto& board:boards) 
        cout<<obj.numRookCaptures(board)<<'\n';
    return 0;
}
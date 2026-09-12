#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Hashing
TC: O(1), since n=9 so O(n²) = O(9²) = O(81) = O(1)
SC: O(1), since n=9 so O(n²) = O(9²) = O(81) = O(1)
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={false};
        bool col[9][9]={false};
        bool box[9][9]={false};
        for(int r=0;r<9;r++) {
            for(int c=0;c<9;c++) {
                char curr=board[r][c];
                if(curr=='.') continue;
                int i=curr-'1';
                int b=(r/3*3)+(c/3);
                if(row[r][i]||col[c][i]||box[b][i])
                    return false;
                row[r][i]=col[c][i]=box[b][i]=true;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    vector<vector<char>> board_1={
        {{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}}
    };
    vector<vector<char>> board_2={
        {{'8','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}}
    };
    cout<<"Board 1 is valid: "<<(obj.isValidSudoku(board_1)?"true":"false")<<'\n';
    cout<<"Board 2 is valid: "<<(obj.isValidSudoku(board_2)?"true":"false")<<'\n';
    return 0;
}
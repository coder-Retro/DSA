#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Approach: Recusrion / DFS / Backtracking
TC: O(m * n * 3^l)
SC: O(l)
*/

class Solution {
    // Helper Data Members
    struct Dir { int r,c; };
    const Dir dirs[4]={{-1,0},{1,0},{0,-1},{0,1}};
    // Helper DFS function
    bool dfs(vector<vector<char>>& b,const string& w,int r,int c,int idx) {
        if(idx==w.size()) return true; // Word Found
        int rows=b.size(),cols=b[0].size();
        if(r<0||c<0||r>=rows||c>=cols) return false; // Invalid Cell
        if(b[r][c]=='.') return false; // Already Visited
        char curr=b[r][c]; // Saving Current Char
        if(curr!=w[idx]) return false; // Different Word
        b[r][c]='.'; // Marking as Visited
        bool found=false; // Word Found Flag
        for(int i=0;i<4&&!found;i++)
            found=dfs(b,w,r+dirs[i].r,c+dirs[i].c,idx+1); // Expanding In 4 Directions
        b[r][c]=curr; // Backtracking
        return found; // Returning Current Path Result
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        for(int row=0;row<rows;row++)
            for(int col=0;col<cols;col++)
                if(dfs(board,word,row,col,0)) return true;
        return false;
    }
};

int main() {
    Solution obj;
    vector<vector<char>> board={
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word_1="ABCCED";
    string word_2="SEE";
    string word_3="ABCB";
    cout<<"Word 1 Exists in Board: "<<(obj.exist(board,word_1)?"true":"false")<<'\n';
    cout<<"Word 2 Exists in Board: "<<(obj.exist(board,word_2)?"true":"false")<<'\n';
    cout<<"Word 3 Exists in Board: "<<(obj.exist(board,word_3)?"true":"false")<<'\n';
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Problem Statement:
You are given an integer n. You are required to write a function
which places n queens on an n x n chessboard such that no two queens
attack each other, and returns all distinct board configurations as
a vector<vector<string>>. Each configuration is represented as a
vector of n strings, where each string has length n, 'Q' marks a
queen, and '.' marks an empty cell.

Constraints:
1. Your approach should be backtracking based.
2. 2 queens attack each other if they share the same row, column, or diagonal.

Note:
You are allowed to make helper functions inside the class.
*/

class Backtracking {
public:
    vector<vector<string>> solveNQueens(int n) {
        // Your Code Here
    }
};

int main() {
    Backtracking obj;
    int n=4;
    vector<vector<string>> boards=obj.solveNQueens(n);
    cout<<'[';
    for(int i=0;i<boards.size();i++) {
        cout<<'[';
        for(int j=0;j<boards[i].size();j++) {
            cout<<'"'<<boards[i][j]<<'"';
            if(j<boards[i].size()-1) cout<<',';
        }
        cout<<']';
        if(i<boards.size()-1) cout<<',';
    }
    cout<<"]\n";
    return 0;
}
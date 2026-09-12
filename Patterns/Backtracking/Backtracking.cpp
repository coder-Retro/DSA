#include<iostream>
#include<vector>
using namespace std;

/*
Backtracking:
Backtracking is a problem solving pattern that allows us
to traverse another path from a choice point after coming
back from the previous path. It is often used when multiple
paths need to be traversed and there are choice points on
these paths. At each choice point, we have a decision to
make and then we follow that choice till next choice. When
the choice leads to a dead end, we come back to the last
choice point undo the step we took for previous choice, and
then go next choice. Consider following backtracking algorithm
for solving the classic "Rat In A Maze" problem. It uses
backtracking technique to find all the paths from top left to
bottom right in a maze (2D array).

Note:
0 represents a wall and 1 represents an open path.
*/

class Backtracking {
    // Helper Data Members
    struct Dir { int r,c; char d; };
    const Dir dirs[4]={{1,0,'D'},{0,-1,'L'},{0,1,'R'},{-1,0,'U'}};
    // Backtracking Function
    void dfs(vector<vector<int>>& m,int r,int c,vector<string>& pS,string& p) {
        int n=m.size();
        if(r<0||c<0||r>=n||c>=n||!m[r][c]) return;
        if(r==n-1 && c==n-1) { pS.push_back(p); return; }
        m[r][c]=0; // Marking As Visited
        for(int i=0;i<4;i++) {
            p.push_back(dirs[i].d); // Choose Path
            dfs(m,r+dirs[i].r,c+dirs[i].c,pS,p); // Traverse Path
            p.pop_back(); // Backtracking
        }
        m[r][c]=1; // Marking as Un-visited
    }
public:
    vector<string> findPaths(vector<vector<int>>& maze) {
        int n=maze.size();
        if(!n||!maze[0][0]||!maze[n-1][n-1]) return {};
        vector<string> paths;
        string path;
        dfs(maze,0,0,paths,path);
        return paths;
    }
};

int main() {
    Backtracking obj;
    vector<vector<int>> maze={
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1}
    };
    vector<string> paths=obj.findPaths(maze);
    cout<<"Paths:\n";
    for(string path:paths) cout<<path<<'\n';
    return 0;
}
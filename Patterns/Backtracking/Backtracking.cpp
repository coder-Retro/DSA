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
    // Backtracking Function
    void dfs(vector<vector<int>>& m,int r,int c,vector<vector<bool>>& v,vector<string>& pS,string& p) {
        int n=m.size();
        if(r<0||c<0||r>=n||c>=n||!m[r][c]||v[r][c]) return;
        if(r==n-1 && c==n-1) {
            pS.push_back(p);
            return;
        }
        v[r][c]=true; // Visited This Cell
        p.push_back('U');
        dfs(m,r-1,c,v,pS,p); // Up Case
        p.pop_back(); // Backtracking
        p.push_back('D');
        dfs(m,r+1,c,v,pS,p); // Down Case
        p.pop_back(); // Backtracking
        p.push_back('R');
        dfs(m,r,c+1,v,pS,p); // Righ Case
        p.pop_back(); // Backtracking
        p.push_back('L');
        dfs(m,r,c-1,v,pS,p); // Left Case
        p.pop_back(); // Backtracking
        v[r][c]=false; // Unvisited This Cell
    }
public:
    vector<string> findPaths(vector<vector<int>>& maze) {
        vector<string> paths;
        string path;
        vector<vector<bool>> visited(maze.size(),vector<bool>(maze.size(),false));
        dfs(maze,0,0,visited,paths,path);
        return paths;
    }
};

int main() {
    Backtracking obj;
    vector<vector<int>> maze={
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    vector<string> paths=obj.findPaths(maze);
    cout<<"Paths:\n";
    for(string path:paths) cout<<path<<'\n';
    return 0;
}
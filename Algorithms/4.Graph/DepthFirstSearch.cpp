#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Use Case:
Depth First Search (DFS) algorithm is a useful graphing
algorithm used to traverse a complex heirarichal data
structures like "Tree" or "Graph" by depths. It is used
where the search space needs to expand from a node to the
depth of its paths one by one. Think of it like standing
at a junction where you have 2 to n paths infront of you.
DFS tells you to start walking on path 1 and keep search
its all of its depth until it is fully traversed, then move
onto path 2 and search its depth and so on until you have
traversed the whole tree or graph. Just like BFS, it is also
used for traversal and searching in tree or graph. Unlike
BFS, DFS does not use an additional data structure like queue
to save the next paths before going to depth of 1. Instead,
it uses recursion and call stack to go to a depth, when that
depth is fully explored, it returns to the previous recursive
call and then explores the next depth. DFS is often used to
find all paths or the first path source node to destination node.
It doesn't guarantee to provide the shortest path like BFS.
Since it is mostly used for finding all path, it marks a node
as visited by temporarily modifying the original graph when a
recurive call is sent for that node. When all depths of that
node are explored and recursive call is about to return, it
marks that node as unvisited before returning so that it can
again be explored from a different path. A good practice example
of DFS would be the classic "Rat in a Maze" problem, which
requires you to find all possible paths from cell (0,0) to cell
(r-1,c-1) in a matrix graph using DFS combined with backtracking.
Examples:
PreOrder, InOrder and PostOrder Traversals of Binary Tree
are initial(Easy to Understand) examples of DFS.
*/

/*
Approach: DFS / Recursion
TC: O(V)
SC: O(V+E)
*/

class DFS {
    void dfs(vector<vector<int>>& maze,int r,int c,int i,int j,string& p,vector<string>& ps) {
        if(i<0 || j<0 || i==r || j==c) return; // Out of Bounds! Cant walk so return.
        if(maze[i][j]==1) return; // Wall! Cant Walk so return.
        if(i==r-1 && j==c-1) { ps.push_back(p); return; } // Destination Reached! Valid Path.
        maze[i][j]=1; // Mark cell as visited.
        p.push_back('U'); dfs(maze,r,c,i-1,j,p,ps); p.pop_back(); // Up Direction.
        p.push_back('D'); dfs(maze,r,c,i+1,j,p,ps); p.pop_back(); // Down Direction.
        p.push_back('L'); dfs(maze,r,c,i,j-1,p,ps); p.pop_back(); // Left Direction.
        p.push_back('R'); dfs(maze,r,c,i,j+1,p,ps); p.pop_back(); // Right Direction.
        maze[i][j]=0; // Mark cell as unvisited.
    }
public:
    vector<string> allPaths(vector<vector<int>>& maze) {
        int r=maze.size();
        int c=maze[0].size();
        vector<string> paths;
        string path;
        dfs(maze,r,c,0,0,path,paths);
        return paths;
    }
};

int main() {
    DFS obj;
    vector<vector<int>> maze={
        {0,1,0,0,0},
        {0,1,0,1,0},
        {0,0,0,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0}
    };
    vector<string> paths=obj.allPaths(maze);
    for(string path:paths) cout<<path<<'\n';
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Use Case:
Depth First Search (DFS) is a useful graph algorithm used
to traverse a complex hierarchical data structure like a
"Tree" or "Graph" by depth. It is used where the search
needs to expand from a node to the depth of its paths, one
by one. Think of it like standing at a junction with 2 to n
paths in front of you. DFS tells you to start walking on
path 1 and keep searching all of its depth until it is
fully traversed, then move on to path 2 and search its
depth, and so on until the whole tree or graph has been
traversed. Just like BFS, it is also used for traversal
and searching in a tree or graph. Unlike BFS, DFS does not
use an additional data structure like a queue to save the
next paths before going to the depth of path 1. Instead, it
uses recursion and the call stack to go to a depth. When
that depth is fully explored, it returns to the previous
recursive call and then explores the next depth. DFS is
often used to find all paths, or the first path, from a
source node to a destination node. Unlike BFS, which finds
the shortest path on an unweighted graph, DFS does not
guarantee the shortest path. When DFS is used to find all
paths, it marks a node as visited by temporarily modifying
the original graph when a recursive call is sent for that
node. When all depths of that node are explored and the
recursive call is about to return, it marks that node as
unvisited before returning, so that it can be explored
again from a different path. This technique is called
backtracking. (In a plain traversal, a node usually stays
marked as visited.) A good practice example of DFS is the
classic "Rat in a Maze" problem, which requires you to find
all possible paths from cell (0,0) to cell (r-1,c-1) in a
matrix graph using DFS combined with backtracking.
Examples:
Preorder, Inorder and Postorder Traversals of a Binary Tree
are initial (easy to understand) examples of DFS.
*/

/*
Approach: Recursion / DFS / Backtracking
TC: O(4^(r*c)), r and c are the rows and columns of the maze
SC: O(r*c)
*/

class DFS {
    void dfs(vector<vector<int>>& maze,int r,int c,int i,int j,string& p,vector<string>& ps) {
        if(i<0 || j<0 || i==r || j==c) return; // Out Of Bounds, Can't Walk
        if(maze[i][j]==1) return; // Wall, Can't Walk
        if(i==r-1 && j==c-1) { ps.push_back(p); return; } // Destination Reached, Valid Path
        maze[i][j]=1; // Marking Cell As Visited
        p.push_back('U'); dfs(maze,r,c,i-1,j,p,ps); p.pop_back(); // Up Direction
        p.push_back('D'); dfs(maze,r,c,i+1,j,p,ps); p.pop_back(); // Down Direction
        p.push_back('L'); dfs(maze,r,c,i,j-1,p,ps); p.pop_back(); // Left Direction
        p.push_back('R'); dfs(maze,r,c,i,j+1,p,ps); p.pop_back(); // Right Direction
        maze[i][j]=0; // Marking Cell As Unvisited
    }
public:
    vector<string> allPaths(vector<vector<int>>& maze) {
        if(maze.empty() || maze[0].empty()) return {};
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
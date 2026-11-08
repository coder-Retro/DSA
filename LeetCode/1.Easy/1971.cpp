#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Approach: BFS / Graph Theory
TC: O(n+e), e is edges.size()
SC: O(n+e), e is edges.size()
*/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto& edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(source);
        vector<bool> visited(n,false);
        visited[source]=true;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            if(node==destination) return true;
            for(int neighbor:graph[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};

int main() {
    Solution obj;
    int n[2]={3,6};
    vector<vector<vector<int>>> e={{{0,1},{1,2},{2,0}},{{0,1},{0,2},{3,5},{5,4},{4,3}}};
    int s[2]={0,0};
    int d[2]={2,5};
    for(int i=0;i<2;i++) cout<<(obj.validPath(n[i],e[i],s[i],d[i])?"true":"false")<<'\n';
    return 0;
}
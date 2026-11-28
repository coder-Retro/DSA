#include<iostream>
#include<vector>
using namespace std;

/*
Approach: BFS / Topological Trimming
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 1 Node Edge Case Check
        if(n==1) return {0};
        // Make Tree and Count Degrees
        vector<vector<int>> tree(n);
        vector<int> degree(n,0);
        for(auto& edge:edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
            degree[edge[0]]++,degree[edge[1]]++;
        }
        // Gather Leaves (degree of leaf == 1)
        vector<int> leaves;
        for(int i=0;i<n;i++) if(degree[i]==1) leaves.push_back(i);
        // Peel Leaves Layer by Layer
        int roots=n;
        vector<int> next_layer;
        while(roots>2) {
            roots-=leaves.size();
            next_layer.clear();
            for(int leaf:leaves) {
                for(int nb:tree[leaf]) {
                    if(--degree[nb]==1) next_layer.push_back(nb);
                }
            }
            leaves=next_layer;
        }
        // Final Roots of MHTs
        return leaves;
    }
};

int main() {
    Solution obj;
    vector<int> n={4,6};
    vector<vector<vector<int>>> edges={
        {
            {1,0},{1,2},{1,3}
        },{
            {3,0},{3,1},{3,2},{3,4},{5,4}
        }
    };
    vector<vector<int>> ans;
    for(int i=0;i<n.size();i++) ans.push_back(obj.findMinHeightTrees(n[i],edges[i]));
    for(auto& roots:ans) {
        cout<<"[";
        for(int i=0;i<roots.size();i++) {
            cout<<roots[i];
            if(i<roots.size()-1) cout<<",";
        }
        cout<<"]\n";
    }
    return 0;
}
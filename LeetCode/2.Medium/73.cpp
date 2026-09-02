#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Linear Marking
TC: O(m * n), m and n are rows and cols of matrix
SC: O(m+n), m and n are rows and cols of matrix
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        vector<int> rows,cols;
        for(int i=0;i<m.size();i++)
            for(int j=0;j<m[i].size();j++)
                if(!m[i][j]) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
        // Nulling Target Rows
        for(int i:rows)
            for(int j=0;j<m[i].size();j++) m[i][j]=0;
        // Nulling Target Cols
        for(int i:cols)
            for(int j=0;j<m.size();j++) m[j][i]=0;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    obj.setZeroes(matrix);
    for(vector<int>& v:matrix) {
        for(int i:v) cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}
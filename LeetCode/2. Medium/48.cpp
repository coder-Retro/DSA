#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transposing Matrix (Nested Loop)
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
                if(i==j) break;
                else swap(matrix[i][j],matrix[j][i]);
        // Reversing Each Row (Nester Loop + Two Pointer)
        for(int i=0;i<matrix.size();i++)
            for(int j=0,k=matrix[i].size()-1;j<k;j++,k--)
                swap(matrix[i][j],matrix[i][k]);
    }
};
int main() {
    Solution s;
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(matrix);
    for(const vector<int>& i:matrix) {
        for(int j:i)
            cout<<j<<" ";
        cout<<'\n';
    }        
    return 0;
}
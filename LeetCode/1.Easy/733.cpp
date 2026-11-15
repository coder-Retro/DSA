#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Approach: BFS / Queue
TC: O(m*n), m and n are rows and columns of image
SC: O(m*n), m and n are rows and columns of image
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int start=image[sr][sc];
        if(start==color) return image;
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()) {
            auto [i,j]=q.front();
            q.pop();
            if(i>0 && image[i-1][j]==start)
                { image[i-1][j]=color; q.push({i-1,j}); }
            if(j>0 && image[i][j-1]==start)
                { image[i][j-1]=color; q.push({i,j-1}); }
            if(i<m-1 && image[i+1][j]==start)
                { image[i+1][j]=color; q.push({i+1,j}); }
            if(j<n-1 && image[i][j+1]==start)
                { image[i][j+1]=color; q.push({i,j+1}); }
        }
        return image;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> image={
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr=1;
    int sc=1;
    int color=2;
    image=obj.floodFill(image,sr,sc,color);
    for(int i=0;i<image.size();i++) {
        cout<<"[";
        for(int j=0;j<image[0].size();j++) {
            cout<<image[i][j];
            if(j<image[0].size()-1) cout<<",";
        }
        cout<<"]\n";
    }
    return 0;
}
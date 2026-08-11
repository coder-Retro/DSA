#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: In-Place Reversal / Bit Manipulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++)
            for(int j=0,k=image[i].size()-1;j<=k;j++,k--) {
                swap(image[i][j],image[i][k]);
                if(j!=k)
                    image[i][k]^=1;
                image[i][j]^=1;
            }
        return image;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> image={{1,1,0},{1,0,1},{0,0,0}};
    image=obj.flipAndInvertImage(image);
    for(vector<int>& v:image) {
        for(int i:v)
            cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}
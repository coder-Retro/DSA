#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> result;
        bool shutdown=false;
        int left,right,top,bottom;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0,val;j<mat[i].size();j++)
            {
                val=mat[i][j];
                if(i==0) left=-1;
                else left=mat[i-1][j];
                if(i==mat.size()-1) right=-1;
                else right=mat[i+1][j];
                if(j==0) top=-1;
                else top=mat[i][j-1];
                if(j==mat[i].size()-1) bottom=-1;
                else bottom=mat[i][j+1];
                if(val>left&&val>right)
                {
                    if(val>top&&val>bottom)
                    {
                        result.push_back(i);
                        result.push_back(j);
                        shutdown=true;
                        break;
                    }
                }
            }
            if(shutdown) break;
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> t[2]={{{1,4},{3,2}},{{10,20,15},{21,30,14},{7,16,32}}};
    vector<int> ans[2];
    for(int i=0;i<2;i++)
    {
        ans[i]=s.findPeakGrid(t[i]);
        for(int j:ans[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
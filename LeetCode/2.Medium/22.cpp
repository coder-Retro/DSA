#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
Approach: Recursion / DFS / Backtracking
TC: O(4ⁿ / √n)
SC: O(n · 4ⁿ / √n)
*/

class Solution {
    void dfs(string& curr,vector<string>& ans,int op,int cl,int n) {
        if(curr.size()==n*2) {
            ans.push_back(curr);
            return;
        }
        if(op<n) {
            curr.push_back('(');
            dfs(curr,ans,op+1,cl,n);
            curr.pop_back(); // Backtracking
        }
        if(cl<op) {
            curr.push_back(')');
            dfs(curr,ans,op,cl+1,n);
            curr.pop_back(); // Backtracking
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        dfs(curr,ans,0,0,n);
        return ans;
    }
};

int main() {
    Solution obj;
    int n=3;
    vector<string> ans=obj.generateParenthesis(n);
    for(string& s:ans) cout<<s<<'\n';
    return 0;
}
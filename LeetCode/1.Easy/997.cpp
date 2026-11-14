#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> balance(n+1,0);
        for(auto& tr:trust) {
            balance[tr[0]]--;
            balance[tr[1]]++;
        }
        for(int i=1;i<=n;i++) if(balance[i]==n-1) return i;
        return -1;
    }
};

int main() {
    Solution obj;
    int n[]={2,3,3};
    vector<vector<vector<int>>> trusts = {
        {{1,2}},
        {{1,3},{2,3}},
        {{1,3},{2,3},{3,1}}
    };
    for(int i=0;i<sizeof(n)/sizeof(*n);i++) cout<<obj.findJudge(n[i],trusts[i])<<'\n';
    return 0;
}
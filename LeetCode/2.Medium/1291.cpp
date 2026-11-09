#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Approach: Sliding Window / Simulation
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    vector<int> sequentialDigits(int low,int high) {
        vector<int> ans;
        string ref="123456789";
        string l=to_string(low);
        string h=to_string(high);
        int currMaxLen=l.size();
        for(int i=0,j=currMaxLen-1;j<(int)ref.size();i++,j++) {
            int n=stoi(ref.substr(i,j-i+1));
            if(n>=low && n<=high) ans.push_back(n);
            if(j==(int)ref.size()-1 && j-i+1<(int)h.size()) {
                i=-1; // loop will do i++ and i becomes 0
                j=currMaxLen-1; // loop will do j++ and j becomes currMaxLen
                currMaxLen++;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    int low=1000;
    int high=13000;
    vector<int> ans=obj.sequentialDigits(low,high);
    for(int i:ans) cout<<i<<" ";
    cout<<'\n';
    return 0;
}
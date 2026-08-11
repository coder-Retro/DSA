#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

/*
Approach: Hashing / Reverse Mapping
TC: O(n log n)
SC: O(n)
*/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> m;
        for(int i=0;i<names.size();i++)
            m[heights[i]]=names[i];
        // Sort in descending order
        int i=0;
        for(auto it=m.rbegin();it!=m.rend();it++) 
            names[i++] = it->second;
        return names;
    }
};

int main() {
    Solution obj;
    vector<string> names={"Mary","John","Emma"};
    vector<int> heights={180,165,170};
    names=obj.sortPeople(names,heights);
    for(string name:names) cout<<name<<" ";
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
Approach: Hashing / Sorting
TC: O(n log n)
SC: O(n)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashMap;
        for(auto str:strs) {
            string word=str;
            sort(word.begin(),word.end());
            hashMap[word].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto key:hashMap) ans.push_back(key.second);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans=obj.groupAnagrams(strs);
    for(vector<string>& group:ans) {
        cout<<"[";
        for(int i=0;i<group.size();i++) {
            cout<<"\""<<group[i]<<"\"";
            if(i<group.size()-1) cout<<",";
        }
        cout<<"]\n";
    }
    return 0;
}
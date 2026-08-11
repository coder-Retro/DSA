#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
Approach: Sorting / Hashing
TC: O(n log n)
SC: O(n)
*/

class Solution {
public:
    string sortVowels(string s) {
        string v="AEIOUaeiou";
        string collected="";
        for(char c:s)
            if(v.find(c)!=string::npos)
                collected+=c;
        sort(collected.begin(),collected.end());
        for(int i=0,vIndex=0;i<s.length();i++)
            if(v.find(s[i])!=string::npos)
                s[i]=collected[vIndex++];
        return s;
    }
};

int main() {
    Solution obj;
    string str="lEetcOde";
    string sorted=obj.sortVowels(str);
    cout<<sorted;
    return 0;
}
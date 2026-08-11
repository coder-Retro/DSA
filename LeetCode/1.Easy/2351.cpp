#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
Approach: Hashing
TC: O(b)
SC: O(1)
*/

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> seen(26,false);
        for(char c:s)
            if(seen[c-'a']) return c;
            else            seen[c-'a']=true;
        return '\0';
    }
};

int main() {
    Solution obj;
    string str="abccbaacz";
    cout<<obj.repeatedCharacter(str);
    return 0;
}
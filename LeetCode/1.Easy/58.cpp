#include<iostream>
#include<string>
using namespace std;

/*
Approach: Reverse Linear Scan
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int last=s.length()-1;
        while(last>=0 && s[last]==' ') last--;
        while(last>=0 && s[last]!=' ') len++,last--;
        return len;
    }
};

int main() {
    Solution obj;
    string sen="luffy is still joyboy";
    cout<<obj.lengthOfLastWord(sen);
    return 0;
}
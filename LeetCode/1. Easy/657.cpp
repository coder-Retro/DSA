#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool judgeCircle(string s) {
        int x=0,y=0;
        for(char c:s) {
            if(c=='U') y++;
            else if(c=='D') y--;
            else if(c=='R') x++;
            else x--;
        }
        return !x && !y;
    }
};
int main() {
    Solution s;
    string str="UDLR";
    if(s.judgeCircle(str))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
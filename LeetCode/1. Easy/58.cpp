#include<iostream>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int last=s.length()-1;
        while(last>=0 && s[last]==' ') last--;
        while(last>=0 && s[last]!=' ')
        {
            len++;
            last--;
        }
        return len;
    }
};
int main()
{
    Solution s;
    string sen="luffy is still joyboy";
    cout<<s.lengthOfLastWord(sen);
    return 0;
}
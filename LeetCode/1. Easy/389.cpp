#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    char findTheDifference(string s,string t) {
        int ans=0;
        for(char c:s) ans^=c;
        for(char c:t) ans^=c;
        return ans;
    }
};
int main() {
    Solution s;
    string str1="abcd";
    string str2="abcde";
    cout<<s.findTheDifference(str1,str2);
    return 0;
}
#include<iostream>
#include<string>
using namespace std;
class Solution  {
public:
    string mergeAlternately(string s1,string s2) {
        string merged="";
        int i=0,j=0;
        while(i<s1.length() || j<s2.length()) {
            if(i<s1.length()) merged+=s1[i++];
            if(j<s2.length()) merged+=s2[j++];
        }
        return merged;
    }
};
int main() {
    Solution s;
    string s1="abc";
    string s2="pqr";
    string s3=s.mergeAlternately(s1,s2);
    cout<<s3;
    return 0;
}
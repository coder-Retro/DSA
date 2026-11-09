#include<iostream>
#include<string>
using namespace std;

/*
Approach: Two Pointers
TC: O(n)
SC: O(1)
*/

class Solution  {
public:
    string mergeAlternately(string s1,string s2) {
        string merged="";
        int i=0,j=0;
        while(i<(int)s1.length() || j<(int)s2.length()) {
            if(i<(int)s1.length()) merged+=s1[i++];
            if(j<(int)s2.length()) merged+=s2[j++];
        }
        return merged;
    }
};

int main() {
    Solution obj;
    string s1="abc";
    string s2="pqr";
    string s3=obj.mergeAlternately(s1,s2);
    cout<<s3;
    return 0;
}
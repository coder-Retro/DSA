#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

/*
Approach: Two Pointers
TC: O(n)
SC: O(n)
*/

class Solution {
private:
    void trim(string& s) {
        if(s.empty()) return;
        // Remove Trailing & Leading Spaces
        int i=0,j=s.size()-1;
        while(i<j && s[i]==' ') i++;
        while(i<j && s[j]==' ') j--;
        if(i==j && s[i]==' ') { s = ""; return; }
        s = s.substr(i,j-i+1);
        // Remove Multiple Internal Spaces
        i = 0, j = 0;
        int n = s.size();
        while(j < n) {
            while(j < n && s[j]!=' ') s[i++] = s[j++];
            while(j < n && s[j]==' ') j++;
            if(j < n) s[i++] = ' ';
        }
        s.resize(i);
    }
    void rev(string& s, int l, int r) {
        if(s.empty()) return;
        while(l < r) swap(s[l++], s[r--]);
    }
    void reverseEach(string& s) {
        int i = 0, j = 0;
        int n = s.size();
        while(j < n) {
            while(j < n && s[j]!=' ') j++;
            rev(s, i, j-1);
            j++;
            i = j;
        }
    }
public:
    string reverseWords(string str) {
        // Trim Extra Spaces
        trim(str);
        // Reverse Entire String
        reverse(str.begin(),str.end());
        // Reverse Words In-Place
        reverseEach(str);
        return str;
    }
};
int main() {
    Solution obj;
    string str = "a good   example";
    cout << obj.reverseWords(str);
    return 0;
}
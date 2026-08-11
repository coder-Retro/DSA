#include<iostream>
#include<string>
using namespace std;

/*
Approach: Two Pointers
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j) {
            while(i<j && !isalnum(s[i])) i++;
            while(i<j && !isalnum(s[j])) j--;
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++,j--;
        }
        return true;
    }
};

int main() {
    Solution obj;
    string str="A man, a plan, a canal: Panama";
    cout<<(obj.isPalindrome(str)?"True":"False");
    return 0;
}
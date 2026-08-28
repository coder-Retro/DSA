#include<iostream>
#include<string>
using namespace std;

/*
Approach: Hashing
TC: O(n)
SC: O(1)
*/

class Solution {
    int mapper(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
public:
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
            if(i+1<s.size() && mapper(s[i])<mapper(s[i+1]))
                ans-=mapper(s[i]);
            else
                ans+=mapper(s[i]);
        return ans;
    }
};

int main() {
    Solution obj;
    string s="MCMXCIV";
    cout<<obj.romanToInt(s);
    return 0;
}
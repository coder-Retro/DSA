#include<iostream>
#include<string>
#include<climits>
using namespace std;

/*
Approach: Simulation
TC: O(n)
SC: O(n)
*/

class Solution {
    string trimSpaces(string s) {
        int check=0;
        while(check<s.size() && s[check]==' ') check++;
        return s.substr(check);
    }
    string invalids(string s) {
        int check=0;
        while(check<s.size() && s[check]=='0') check++;
        return s.substr(check);
    }
    string extract(string s) {
        int i=0;
        while(i<s.size()&&s[i]>='0'&&s[i]<='9') i++;
        return s.substr(0,i);
    }
public:
    int myAtoi(string s) {
        s=trimSpaces(s);
        bool negative=(s[0]=='-'?true:false);
        if(negative || s[0]=='+') s=s.substr(1);
        s=invalids(s);
        string num=extract(s);
        long long ans=0;
        for(char c:num) {
            ans=ans*10+(c-'0');
            if(negative && -ans<INT_MIN) return INT_MIN;
            if(!negative && ans>INT_MAX) return INT_MAX;
        }
        return (negative?-ans:ans);
    }
};

int main() {
    Solution obj;
    string s=" -042";
    cout<<obj.myAtoi(s);
    return 0;
}
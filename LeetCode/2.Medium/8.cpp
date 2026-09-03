#include<iostream>
#include<string>
#include<climits>
using namespace std;

/*
Approach: Simulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) return 0;
        int i=0,n=s.size();
        // Remove Spaces
        while(i<n && s[i]==' ') i++;
        // Check End
        if(i==n) return 0;
        // Check Sign
        int sign=1;
        if(s[i]=='-') { sign=-1; i++; }
        else if(s[i]=='+') i++;
        // Read And Convert Valid Digits
        long long ans=0;
        while(i<n && isdigit(s[i])) {
            int digit=static_cast<int>(s[i]-'0');
            ans=ans*10+digit;
            if(sign*ans<=INT_MIN) return INT_MIN;
            if(sign*ans>=INT_MAX) return INT_MAX;
            i++;
        }
        return static_cast<int>(sign*ans);
    }
};

int main() {
    Solution obj;
    string s=" -042";
    cout<<obj.myAtoi(s);
    return 0;
}
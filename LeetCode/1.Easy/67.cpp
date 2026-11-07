#include<iostream>
#include<vector>
#include<string>
#include<utility>
using namespace std;

/*
Approach: Two Pointers / String Manipulation
TC: O(max(n,m)), n and m are lengths of string a and b
SC: O(1)
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()) swap(a,b);
        int i=a.size()-1,j=b.size()-1;
        int carry=0;
        while(i>=0) {
            int sum=carry+(a[i]-'0');
            if(j>=0) sum+=b[j--]-'0';
            a[i--]=(sum%2)+'0';
            carry=sum/2;
            if(j<0 && !carry) break;
        }
        if(carry) a="1"+a;
        return a;
    }
};

int main() {
    Solution obj;
    vector<pair<string,string>> tests = {{"11","1"},{"1010","1011"}};
    for(auto& [a,b]:tests) cout<<obj.addBinary(a,b)<<'\n';
    return 0;
}
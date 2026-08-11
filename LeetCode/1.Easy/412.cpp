#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Approach: Simulation / Modulo Check
TC: O(n)
SC: O(n) 
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; i++)
            if(i%3 == 0 && i%5 == 0) ans.push_back("FizzBuzz");
            else if(i%3 == 0)        ans.push_back("Fizz");
            else if(i%5 == 0)        ans.push_back("Buzz");
            else                     ans.push_back(to_string(i));
        return ans;
    }
};

int main() {
    Solution obj;
    int n=15;
    vector<string> ans=obj.fizzBuzz(n);
    for(const string& s:ans) cout<<s<<'\n';
    return 0;
}
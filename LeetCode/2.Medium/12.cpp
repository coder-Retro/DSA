#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

/*
Approach: Greedy / Hashing
TC: O(1)
SC: O(1)
*/

class Solution {
    vector<pair<int,string>> mapper {
        {1000,"M"},{900,"CM"},{500,"D"},
        {400,"CD"},{100,"C"},{90,"XC"},
        {50,"L"},{40,"XL"},{10,"X"},
        {9,"IX"},{5,"V"},{4,"IV"},
        {1,"I"}
    };
public:
    string intToRoman(int num) {
        string ans;
        for(const auto& [val,rom]:mapper) {
            if(!num) break;
            while(num>=val) {
                ans+=rom;
                num-=val;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    int n=1994;
    cout<<obj.intToRoman(n);
    return 0;
}
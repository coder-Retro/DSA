#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Arithmetic Reversal
TC: O(d), d = digits in num
SC: O(1)
*/

class Solution {
public:
    int reverse(int x) {
        long rev=0;
        while(x!=0) {
            rev=rev*10+x%10;
            x/=10;
        }
        if(rev<-2147483648||rev>2147483647) return 0;
        return rev;
    }
};

int main() {
    Solution obj;
    vector<int> x={123,-123,120,1534236469};
    for(int i=0;i<x.size();i++)
        cout<<obj.reverse(x[i])<<'\n';
    return 0;
}
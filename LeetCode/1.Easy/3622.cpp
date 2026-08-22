#include<iostream>
using namespace std;

/*
Approach: Modulo Digit Extraction
TC: O(d), d = num of digits in given number
SC: O(1)
*/

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,pro=1,copy=n;
        while(copy) {
            sum+=(copy%10);
            pro*=(copy%10);
            copy/=10;
        }
        return !(n%(sum+pro));
    }
};

int main() {
    Solution obj;
    int n=99;
    cout<<(obj.checkDivisibility(n)?"true":"false")<<'\n';
    return 0;
}
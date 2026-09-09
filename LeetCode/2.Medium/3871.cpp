#include<iostream>
using namespace std;

/*
Approach: Math
TC: O(log n)
SC: O(1)
*/

class Solution {
public:
    long long countCommas(long long n) {
        long long commas=0;
        long long range=1000;
        while(range<=n) {
            commas+=(n-range+1);
            range*=1000;
        }
        return commas;
    }
};

int main() {
    Solution obj;
    long long n=1002;
    cout<<obj.countCommas(n);
    return 0;
}
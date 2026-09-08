#include<iostream>
using namespace std;

/*
Approach: Math
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int countCommas(int n) {
        return (n<1000)?0:n-999;
    }
};

int main() {
    Solution obj;
    int n=1002;
    cout<<obj.countCommas(n);
    return 0;
}
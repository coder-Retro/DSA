#include<iostream>
using namespace std;
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n%2)?n*2:n;
    }
};
int main() {
    Solution s;
    int n=5;
    cout<<s.smallestEvenMultiple(n);
    return 0;
}
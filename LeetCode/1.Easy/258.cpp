#include<iostream>
using namespace std;

/*
Approach: Congruence Formula
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int addDigits(int num) {
        if(!num) return 0;
        return 1+(num-1)%9;
    }
};

int main() {
    Solution obj;
    int  num=10;
    cout<<obj.addDigits(num);
    return 0;
}
#include<iostream>
using namespace std;

/*
Approach: Game Theory
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};

int main() {
    Solution obj;
    int stones=4;
    if(obj.canWinNim(stones)) cout<<"Can Win!";
    else                      cout<<"Can't Win!";
    return 0;
}
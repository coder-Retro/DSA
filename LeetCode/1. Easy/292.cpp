#include<iostream>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};
int main() {
    Solution s;
    int stones=4;
    if(s.canWinNim(stones))
        cout<<"Can Win!";
    else
        cout<<"Can't Win!";
    return 0;
}
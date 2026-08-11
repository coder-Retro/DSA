#include<iostream>
using namespace std;

/*
Approach: Arithmatic Reversal
TC: O(d), d = digits of num
SC: O(1)
*/

class Solution {
public:
    bool isPalindrome(int num) {
        long long reversed=0;
        int copy=num;
        while(copy>0) {
            reversed=reversed*10+copy%10;
            copy/=10;
        }
        if(reversed==num) return true;
        return false;
    }
};

int main() {
    Solution obj;
    (obj.isPalindrome(121))?cout<<"true":cout<<"false";
    return 0;
}
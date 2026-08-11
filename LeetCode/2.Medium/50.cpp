#include<iostream>
using namespace std;

/*
Approach: Iterative Power Calculation
TC: O(log n)
SC: O(1)
*/

class Solution {
public:
    double myPow(double x,int n) {
        long long power=n;
        if (power<0){
            power=-power;
            x=1/x;
        }
        double ans=1;
        while(power) {
            if(power%2) ans*=x;
            x*=x;
            power/=2;
        }
        return ans;
    }
};

int main() {
    Solution obj;
    cout<<obj.myPow(2,3);
    return 0;
}
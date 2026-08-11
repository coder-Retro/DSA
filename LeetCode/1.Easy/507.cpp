#include<iostream>
using namespace std;

/*
Approach: Iterative Summation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=0;
        for(int i=1;i<=num/2;i++)
            if(num%i==0) sum+=i;
        return (sum==num);
    }
};

int main() {
    Solution obj;
    int num=28;
    cout<<(obj.checkPerfectNumber(num)?"true":"false");
    return 0;
}
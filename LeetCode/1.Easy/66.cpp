#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Linear Addition
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum=1;
        for(int i=digits.size()-1;i>=0;i--) {
            sum+=digits[i];
            digits[i]=sum%10;
            sum/=10;
            if(!sum) break;
        }
        if(sum) {
            digits.resize(digits.size()+1);
            for(int i=digits.size()-1;i>0;i--)
                digits[i]=digits[i-1];
            digits[0]=sum;
        }
        return digits;
    }
};

int main() {
    Solution obj;
    vector<int> digits={9,9,9};
    digits=obj.plusOne(digits);
    for(int i:digits) cout<<i;
    return 0;
}
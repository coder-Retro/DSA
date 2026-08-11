#include<iostream>
using namespace std;

/*
Approach: Direct Addition
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int sum(int num1,int num2){
        return num1+num2;
    }
};

int main() {
    Solution obj;
    int num1=12;
    int num2=5;
    cout<<obj.sum(num1,num2);
    return 0;
}
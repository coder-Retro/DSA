#include<iostream>
using namespace std;
class Solution {
public:
    int numberOfSteps(int num) {
        int steps=0;
        while(num) {
            if(num%2) num-=1;
            else      num/=2;
            steps++;
        }
        return steps;
    }
};
int main() {
    Solution s;
    int num=14;
    cout<<s.numberOfSteps(num);
    return 0;
}
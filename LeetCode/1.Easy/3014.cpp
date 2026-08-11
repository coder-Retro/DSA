#include<iostream>
#include<string>
using namespace std;

/*
Approach: Modulo Arithematics
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    int minimumPushes(string word) {
        int blocks=word.size()/8;
        int remain=word.size()%8;
        int totalPush=0;
        switch(blocks) {
            case 0: totalPush+=(remain);      break;
            case 1: totalPush+=(8+2*remain);  break;
            case 2: totalPush+=(24+3*remain); break;
            case 3: totalPush+=(48+4*remain); break;
        }
        return totalPush;
    }
};

int main() {
    Solution obj;
    string s="xycdefghij";
    cout<<obj.minimumPushes(s);
    return 0;
}
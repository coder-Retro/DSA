#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int freq[5]={0};
        for(char c:s) {
            if(c=='b') freq[0]++;
            else if(c=='a') freq[1]++;
            else if(c=='l') freq[2]++;
            else if(c=='o') freq[3]++;
            else if(c=='n') freq[4]++;
        }
        freq[2]/=2;
        freq[3]/=2;
        int minFreq=freq[0];
        for(int i=1;i<5;i++)
            if(freq[i]<minFreq) minFreq=freq[i];
        return minFreq;
    }
};
int main() {
    Solution s;
    string str="loonbalxballpoon";
    cout<<s.maxNumberOfBalloons(str);
    return 0;
}
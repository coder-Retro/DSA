#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters,char target) {
        for(char c:letters)
            if(c>target) return c;
        return letters[0];
    }
};
int main() {
    Solution s;
    vector<char> letters={'c','f','j'};
    char target='a';
    cout<<s.nextGreatestLetter(letters,target);
    return 0;
}
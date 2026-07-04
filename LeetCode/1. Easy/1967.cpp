#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int numOfStrings(vector<string>& patterns,string word) {
        int answer=0;
        for(const string& s:patterns)
            if(word.find(s)!=string::npos)
                answer++;
        return answer;
    }
};
int main() {
    Solution s;
    vector<string> patterns={"a","abc","bc","d"};
    string word="abc";
    cout<<s.numOfStrings(patterns,word);
    return 0;
}
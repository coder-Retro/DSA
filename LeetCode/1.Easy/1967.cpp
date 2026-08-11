#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Approach: Linear Matching
TC: O(n)
SC: O(1)
*/

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
    Solution obj;
    vector<string> patterns={"a","abc","bc","d"};
    string word="abc";
    cout<<obj.numOfStrings(patterns,word);
    return 0;
}
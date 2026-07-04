#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        for(int i=0,j=s.size()-1;i<j;i++,j--)
            swap(s[i],s[j]);
    }
};
int main()
{
    Solution s;
    vector<char> str={'h','e','l','l','o'};
    s.reverseString(str);
    for(char i:str) cout<<i;
    return 0;
}
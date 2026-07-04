#include<iostream>
using namespace std;
class Solution
{
public:
    int strStr(string haystack,string needle)
    {
        int a=haystack.length();
        int b=needle.length();
        for(int i=0;i<=a-b;i++)
        {
            if(haystack[i]==needle[0])
            {
                int j=0;
                while(j<b && haystack[i+j]==needle[j])
                {
                    j++;
                }
                if(j==b) return i;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    cout<<s.strStr("sadbutsad","sad");
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> open;
        char target;
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                open.push_back(s[i]);
            else
            {
                if(open.size()==0) return false;
                target=open.back();
                if(s[i]==')'&&target=='(') open.pop_back();
                else if(s[i]=='}'&&target=='{') open.pop_back();
                else if(s[i]==']'&&target=='[') open.pop_back();
                else return false;
            }
        }
        if(open.size()==0) return true;
        else return false;
    }
};
int main()
{
    Solution s;
    string t[8]={"()","()[]{}","(]","([])","([)]","[","((","(])"};
    for(int i=0;i<8;i++)
        (s.isValid(t[i]))?cout<<"true\n":cout<<"false\n";
    return 0;
}
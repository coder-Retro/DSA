#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int reverseBits(int n)
    {
        int ans=0;
        long pow=1;
        while(pow*2<=n) pow*=2;
        vector<int> bin;
        while(pow>0)
        {
            if(pow<=n)
            {
                n-=pow;
                bin.push_back(1);
            }
            else bin.push_back(0);
            pow>>=1;
        }
        for(int i=0,j=bin.size()-1;i<j;i++,j--)
            swap(bin[i],bin[j]);
        for(int i=bin.size();i<32;i++) bin.push_back(0);
        pow=1;
        while(bin.size()>0)
        {
            if(bin.back()==1) ans+=pow;
            bin.pop_back();
            pow*=2;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout<<s.reverseBits(43261596)<<'\n';
    return 0;
}
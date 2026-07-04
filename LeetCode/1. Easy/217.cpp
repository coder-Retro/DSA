#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_set<int> s;
       int i=0;
       int prev_size;
       while(i<nums.size())
       {
            prev_size=s.size();
            s.insert(nums[i++]);
            if(prev_size==s.size()) return true;
       }
       return false;
    }
};
int main()
{
    Solution s;
    vector<int> v={1,2,3,4,5,1};
    vector<int> u={1,2,3,4,5,6};
    cout<<"v duplicates Exist ? ";
    if(s.containsDuplicate(v)) cout<<"(True)\n";
    else              cout<<"(False)\n";
    cout<<"u duplicates Exist ? ";
    if(s.containsDuplicate(u)) cout<<"(True)\n";
    else              cout<<"(False)\n";
    return 0;
}
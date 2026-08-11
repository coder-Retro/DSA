#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
Approach: Hashing 
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i:nums)
            if(!s.insert(i).second) return true;
        return false;
    }
};

int main() {
    Solution obj;
    vector<int> v={1,2,3,4,5,1};
    vector<int> u={1,2,3,4,5,6};
    cout<<"v duplicates Exist ? ";
    if(obj.containsDuplicate(v)) cout<<"(True)\n";
    else                         cout<<"(False)\n";
    cout<<"u duplicates Exist ? ";
    if(obj.containsDuplicate(u)) cout<<"(True)\n";
    else                         cout<<"(False)\n";
    return 0;
}
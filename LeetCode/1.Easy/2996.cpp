#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
Approach: Hashing / Simulation
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(),nums.end());
        int sum=nums[0];
        for(int i=1;i<nums.size();i++)
            if(nums[i]==nums[i-1]+1) sum+=nums[i];
            else                     break;
        while(hash.contains(sum)) sum++;
        return sum;
    }
};

/*
Explanation:
First make a hash table using unordered_set<int> which contains
all values from the vector. Then iterate from the beginning of 
the given vector and keep summing elements until the element are
sequential, meaning the ith element is 1 more in magnitude than
the ith-1 element. When this condition fails, break the loop.
Now we dont want to return the sum if the sum value exists in
the input vector. So keep increasing the sum by 1 until it no
longer exists in the hash table we created earlier. Then return
the sum.
*/

int main() {
    Solution obj;
    vector<vector<int>> nums={{1,2,3,2,5},{3,4,5,1,12,14,13},{38},{14,9,6,9,7,9,10,4,9,9,4,4}};
    for(vector<int>& v:nums)
        cout<<obj.missingInteger(v)<<'\n';
    return 0;
}
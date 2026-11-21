#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Use Case:
Radix sort is a non-comparison sorting algorithm. It sorts
integers (negative included) digit by digit, from the least
significant to the most significant, using a stable bucket
pass for each digit. Since % keeps the sign of the dividend,
a digit lies in [-9, 9], so 19 buckets are used (digit + 9).
*/

/*
Approach: Bucket Distribution / Hashing
TC: O(d*n), d = number of digits in the largest absolute value
SC: O(n)
*/

class Solution {
public:
    void radixSort(vector<int>& nums) {
        queue<int> table[19];
        int maxDigs=0;
        for(int i=0;i<nums.size();i++) {
            int curr=nums[i];
            int digs=0;
            while(curr) {
                digs++;
                curr/=10;
            }
            if(digs>maxDigs) maxDigs=digs;
        }
        long long hasher=1;
        for(int i=0;i<maxDigs;i++) {
            for(int num:nums) {
                int dig=(num/hasher%10+9);
                table[dig].push(num);
            }
            int it=0;
            for(auto& q:table) {
                while(!q.empty()) {
                    nums[it++]=q.front();
                    q.pop();
                }
            }
            hasher*=10;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums[3]={{2,0,-4,5,-1,3},{4,5,1,2},{13,4,51,2,60,7,8,-33,102,-200}};
    for(int i=0;i<3;i++) {
        s.radixSort(nums[i]);
        for(int j:nums[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
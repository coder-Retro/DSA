#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Approach: Linear Pass / Max Tracking
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr_alt=0;
        int max_alt=0;
        for(int i:gain) {
            curr_alt+=i;
            max_alt=max(max_alt,curr_alt);
        }
        return max_alt;
    }
};

int main() {
    Solution obj;
    vector<int> gain={-5,1,5,0,-7};
    cout<<obj.largestAltitude(gain);
    return 0;
}
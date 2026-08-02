#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Game Theory Logic
TC: O(1)
SC: O(1)
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

/*
Explanation: 
Since Aclice gets to choose either odd or even pile
from either end. Therefore Alice has the choice to
pick all the even piles or all the odd piles while
giving all the other to Bob to pick, Since leetcode
guarantees that number of piles is always even, Alice
just need to see the total sum of even piles and total
sum of odd piles. Whichever one is larger, Alice picks
that and locks Bob in the other. This is why with even
number of piles, Alice always wins.
*/

int main() {
    Solution obj;
    vector<int> piles={5,3,4,5};
    cout<<(obj.stoneGame(piles)?"true":"false");
    return 0;
}
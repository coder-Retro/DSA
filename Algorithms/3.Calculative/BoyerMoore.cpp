#include<iostream>
#include<vector>
using namespace std;

/*
Use Case:
Boyer Moore's algorithm is used to find the majority
element in a data set, the majority element is
defined as an element that appears more times
than half the size of dataset. Which means that
its frequency is greater than the sum of all the
frequencies of other elements in the data set.
And this is the working principle of Boyer Moore's
Algo. It works by finding the largest Frequency.
*/

/*
Approach: Greedy
TC: O(n)
SC: O(1)
*/

class BoyerMoore {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0;
        int major;
        for(int i:nums) {
            if(!freq) major=i;
            if(i==major) freq++;
            else         freq--;
        }
        return major;
    }
};

int main() {
    BoyerMoore obj;
    vector<int> nums={1,5,3,5,4,5,6,5,5,5};
    cout<<obj.majorityElement(nums);
    return 0;
}
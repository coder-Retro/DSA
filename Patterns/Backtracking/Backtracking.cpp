#include<iostream>
#include<vector>
using namespace std;

/*
Backtracking:
Backtracking is a problem solving pattern that allows us
to traverse another path from a choice point after coming
back from the previous path. It is often used when multiple
paths need to be traversed and there are choice points on
these paths. At each choice point, we have a decision to
make and then we follow that choice till next choice. When
the choice leads to a dead end, we come back to the last
choice point undo the step we took for previous choice, and
then go next choice. Consider following backtracking algorithm
for finding all the subsets of an array.
*/

// Backtracking Function
vector<int> initial_ans; // Passed As "ans" for first function call
int initial_i=0; // Passed as "i" for first function call
void subsets(const vector<int>& nums,vector<int>& ans,int i) {
    // Base Case, Subset Reached
    if(i==nums.size()) {
        for(int element:ans) cout<<element<<" ";
        cout<<'\n';
        return;
    }
    // Include Current Value (Choice 1)
    ans.push_back(nums[i]);
    subsets(nums,ans,i+1);
    // Exclude Current Value (Choice 2)
    ans.pop_back(); // Backtracking
    subsets(nums,ans,i+1);
}
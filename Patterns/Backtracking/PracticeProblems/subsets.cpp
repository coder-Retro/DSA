#include<iostream>
#include<vector>
using namespace std;

/*
Problem Statement:
You are given a vector<int> nums. You are required to write a function
which calculates and returns all subsets of nums as a vector<vector<int>>.

Constraints:
1. Your approach should be backtracking based.

Note:
You are allowed to make helper functions inside the class.
*/

class Backtracking {
public:
    vector<vector<int>> subsets(const vector<int>& nums) {
        // Your Code Here
    }
};

int main() {
    Backtracking obj;
    vector<int> nums={1,2,3};
    vector<vector<int>> subsets=obj.subsets(nums);
    cout<<'[';
    for(int i=0;i<subsets.size();i++) {
        cout<<'[';
        for(int j=0;j<subsets[i].size();j++) {
            cout<<subsets[i][j];
            if(j<subsets[i].size()-1) cout<<',';
        }
        cout<<']';
        if(i<subsets.size()-1) cout<<',';
    }
    cout<<"]\n";
    return 0;
}
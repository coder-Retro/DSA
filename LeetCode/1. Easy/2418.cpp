#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names,vector<int>& heights) {
        for(int i=0,maxIndex;i<heights.size();i++) {
            maxIndex=i;
            for(int j=i+1;j<heights.size();j++)
                if(heights[maxIndex]<heights[j]) maxIndex=j;
            if(i!=maxIndex) {
                swap(heights[i],heights[maxIndex]);
                swap(names[i],names[maxIndex]);
            }
        }
        return names;
    }
};
int main() {
    Solution s;
    vector<string> names={"Mary","John","Emma"};
    vector<int> heights={180,165,170};
    names=s.sortPeople(names,heights);
    for(string name:names) cout<<name<<" ";
    return 0;
}
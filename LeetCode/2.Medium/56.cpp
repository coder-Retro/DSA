#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Helper Definition & Functions
void print(const vector<vector<int>>& v) {
    cout<<'[';
    for(int i=0;i<v.size();i++) {
        cout<<'[';
        for(int j=0;j<v[i].size();j++) {
            cout<<v[i][j];
            if(j!=v[i].size()-1) cout<<",";
        }
        cout<<']';
        if(i!=v.size()-1) cout<<",";
    }
    cout<<"]\n";
}

/*
Approach: Sorting / Min Max Tracking
TC: O(n log n)
SC: O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        int i=0,n=intervals.size();
        while(i<n) {
            int start=intervals[i][0];
            int end=intervals[i][1];
            int j=i+1;
            while(j<n && intervals[j][0]<=end) {
                end=max(end,intervals[j][1]);
                j++;
            }
            merged.push_back({start,end});
            i=j;
        }
        return merged;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
    cout<<"Input:  "; print(intervals);
    vector<vector<int>> merged=obj.merge(intervals);
    cout<<"Output: "; print(merged);
    return 0;
}
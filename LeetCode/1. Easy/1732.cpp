#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current_altitude=0;
        int maximum_altitude=0;
        for(int i=0;i<gain.size();i++) {
            current_altitude+=gain[i];
            if(current_altitude>maximum_altitude)
                maximum_altitude=current_altitude;
        }
        return maximum_altitude;
    }
};
int main() {
    Solution s;
    vector<int> gain={-5,1,5,0,-7};
    cout<<s.largestAltitude(gain);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& h) {
        int water=0;
        int Lmax=0;
        int Rmax=0;
        int i=0,j=h.size()-1;
        while(i<j) {
            if(h[i]<h[j]) {
                if(h[i]>Lmax) Lmax=h[i];
                else water+=(Lmax-h[i]);
                i++;
            } else {
                if(h[j]>Rmax) Rmax=h[j];
                else water+=(Rmax-h[j]);
                j--;
            }
        }
        return water;
    }
};
int main() {
    Solution s;
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(height);
    return 0;
}
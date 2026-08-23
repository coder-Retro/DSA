#include<vector>
#include<algorithm>
using namespace std;

/*
Greedy:
Greedy algorithms work by selecting the local best answer.
This means that they don't give the right solution instantly
but look at the available options at each step and select an
optimal answer from these options. At the end of algorithm,
they hold the actual best answer. Consider driving from 'A'
to 'B'. In your path, you stop at several junstions. At each
junction, you look for the path with the lightest traffic to
reach your destination in minimal time. You stop and junction
'C' and look at three available paths i.e {pA,pB,pC}. You see
that pA and pB are crowded with traffic and pC is clear, so
you choose pC. This happens several times and you decide your
path using the same criteria again to reach you destination
'B' avoiding the maximum amount of traffic. You can only see
the options available at the current junction and you choose
the best from them. This is how a greedy algorithm works.

Example:
Following function is taken from leetcode hard. It's called
trapping rain water. It combines Two Pointers with Greedy to
achieve the solution. The problem statement says that we are
given an array which shows elevations. It's raining and the
water is accumulating in the valleys between these elevations.
The function returns the total stored units of water. It works
by using leftMax and rightMax as references to decide how much
water can accumulate at the current point and keeps switching
to maximize the stored water.
*/

// Greedy Function
int trap(const vector<int>& height) {
    if(height.empty()) return 0;
    int water=0;
    int leftMax=0,rightMax=0;
    int l=0,r=height.size()-1;
    while(l<r) {
        if(height[l]<height[r]) {
            if(height[l]>leftMax) leftMax=height[l];
            else water+=(leftMax-height[l]);
            l++;
        } else {
            if(height[r]>rightMax) rightMax=height[r];
            else water+=(rightMax-height[r]);
            r--;
        }
    }
    return water;
}
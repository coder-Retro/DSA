#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Seive of Eratosthenes
TC: O(n log log n)
SC: O(n)
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<3) return 0;
        int count=n/2;
        vector<bool> isPrime(n,true);
        for(long long i=3;i*i<n;i+=2) {
            if(!isPrime[i]) continue;
            for(long long j=i*i;j<n;j+=2*i) {
                if(isPrime[j]) {
                    isPrime[j]=false;
                    count--;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution obj;
    int n=499979;
    cout<<obj.countPrimes(n);
    return 0;
}
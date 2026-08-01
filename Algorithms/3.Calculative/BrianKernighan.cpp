#include<iostream>
using namespace std;

/*
Use Case:
BrianKernighan's Algorithm is used when we want
to count the number of set bits in an unsigned
32 bit number. It works by subtracting 1 from
the number (if the number isn't 0), then &s the
number-1 with number itself to remove that one
bit and then it increases the count variable. It
run the exact amount of times as the number of
one bits in the number.
*/

/*
Approach: Bit Manipulation
TC: O(k), k = number of set bits
SC: O(1)
*/

// Brian Kernighan Class
class BrianKernighan {
public:
    int countSetBits(int n) {
        int count=0;
        while(n) {
            n&=(n-1);
            count++;
        }
        return count;
    }
};
// Main Function
int main() {
    BrianKernighan obj;
    int n=11;
    cout<<obj.countSetBits(n);
    return 0;
}
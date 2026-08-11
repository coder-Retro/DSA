#include<iostream>
#include<vector>
using namespace std;

/*
Approach: Binary Search
TC: O(log n)
SC: O(1)
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters,char target) {
        if(target>=letters.back()) return letters[0];
        int i=0,j=letters.size()-1;
        while(i<=j) {
            int mid=i+(j-i)/2;
            if(letters[mid]>target) j=mid-1;
            else                    i=mid+1;
        }
        return letters[i];
    }
};

int main() {
    Solution obj;
    vector<char> letters={'c','f','j'};
    char target='a';
    cout<<obj.nextGreatestLetter(letters,target);
    return 0;
}
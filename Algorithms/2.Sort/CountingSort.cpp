#include<iostream>
#include<vector>
using namespace std;

/*
Use Case:
Counting sort can be used to sort an array that consist of elements
belonging in a certain fixed sized range, like the 26 letters in the
english alphabet. It works by performing a linear walk through the
array and count frequencies of each element in that range. Then it
starts writing into the original array per element's frequency in
linear time and constant space.
*/

/*
Approach: Frequency Accumulation
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    void countingSort(vector<char>& chars) {
        int freq[26]={0};
        for(char c:chars) freq[c-'a']++;
        for(int i=0,j=0;i<26;i++)
            while(freq[i]--) chars[j++]='a'+i;
    }
};
int main() {
    Solution s;
    vector<char> chars={'v','a','s','t','a','a','d','x','z','y','h','u','i','u','g','d','q','w'};
    s.countingSort(chars);
    for(char c:chars) cout<<c<<" ";
    return 0;
}
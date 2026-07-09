#include<iostream>
#include<string>
using namespace std;

/*
Two Pointers:
Two Pointers is a classic technique used in DSA due to its
capability to solve several complex problems using the O(n)
time complexity. It works with array, vectors, strings and
such containers. It cannot be used on an ordinary int,char
or such others.

Although pointer movement can vary depending on the nature
of the problem it is being applied on but lets start by
looking at easy examples for now, following are some cases
where two pointers approach can be used to achieve O(n):

1. Determine if given string is palindrome.
2. Reverse an array, vector or string in-place.
3. Find Intersection Node in two lists.

The first two on these cases follow convergence movement,
meaning that the two pointes start from beginning and end
of the given arguement and then they converge towards the
centre.

The third case follows a bit of a complex movement which
requires the two pointer to start from the heads of each
list and alternate between each other untill they become
equal (Land on the same Node, which is the intersection)
*/

// TwoPointers Function
bool isPalindrome(const string& s){
    for(int i=0,j=s.length()-1;i<j;i++,j--)
        if(s[i]!=s[j]) return false;
    return true;
}
// Main Function
int main()
{
    string str;
    cout<<"Enter String : ";
    getline(cin,str);
    if(isPalindrome(str))
        cout<<str<<" is palindrome";
    else
        cout<<str<<" is not palindrome";
    return 0;
}
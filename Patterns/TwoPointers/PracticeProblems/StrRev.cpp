#include <iostream>
#include <utility>
using namespace std;

/*
Problem Statement:
You are required to write a string reversal
function. The function will return void and
take a string s passed by reference.

Constraints:
1. You must achieve this using two pointers.
2. You are allowed to use only swap from built-in functions.
*/

// Reverse Class
class TwoPointer {
public:
    void strRev(string& s) {
        // Your Code Here
    }
};

// Main Function
int main() {
    TwoPointer obj;
    string str;
    cout<<"Enter String : ";
    getline(cin,str);
    obj.strRev(str);
    cout<<"Reversed String : "<<str<<'\n';
    return 0;
}
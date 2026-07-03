#include<iostream>
#include"vector"
using namespace std;
// Main Function
int main()
{
    vector<int> vec;
    int sizeOfVec;
    cout<<"Enter size of vector : ";
    cin>>sizeOfVec;
    cout<<"Enter Vector : ";
    for(int i=0,val;i<sizeOfVec;i++)
    {
        cin>>val;
        vec.push_back(val);
    }
    cout<<"Vector : ";
    for(int i:vec)
        cout<<i<<" ";
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        for(int i=0,min;i<arr.size()-1;i++)
        {
            min=i;
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[j]<arr[min]) min=j;
            }
            if(i!=min) swap(arr[i],arr[min]);
        }
        int diff=arr[1]-arr[0];
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i+1]-arr[i]!=diff) return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> arr={3,5,1};
    (s.canMakeArithmeticProgression(arr))?cout<<"true":cout<<"false";
    return 0;
}
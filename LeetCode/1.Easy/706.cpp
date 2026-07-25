#include<iostream>
#include<vector>
using namespace std;

/*
Constructor:
Approach: Initialization
TC: O(n)
SC: O(n)

put:
Approach: Index Updation
TC: O(1)
SC: O(1)

get:
Approach: Index Retrieval
TC: O(1)
SC: O(1)

remove:
Approach: Index Updation
TC: O(1)
SC: O(1)
*/

class MyHashMap {
private:
    vector<int> v;
public:
    MyHashMap() { v=vector<int>(1000001,-1); }
    
    void put(int key, int value) { v[key]=value; }
    
    int get(int key) { return v[key]; }
    
    void remove(int key) { v[key]=-1; }
};
int main() {
    MyHashMap obj;          cout<<"null, ";
    obj.put(1,1);           cout<<"null, ";
    obj.put(2,2);           cout<<"null, ";
    cout<<obj.get(1)<<", ";
    cout<<obj.get(3)<<", ";
    obj.put(2,1);           cout<<"null, ";
    cout<<obj.get(2)<<", ";
    obj.remove(2);          cout<<"null, ";
    cout<<obj.get(2);
}
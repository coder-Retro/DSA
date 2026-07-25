#include<iostream>
#include<vector>
using namespace std;

/*
Constructor:
Approach: Initialization
TC: O(n)
SC: O(n)

add:
Approach: Index Updation
TC: O(1)
SC: O(1)

remove:
Approach: Index Updation
TC: O(1)
SC: O(1)

contains:
Approach: Index Retrieval
TC: O(1)
SC: O(1)
*/

class MyHashSet {
private:
    vector<bool> v;
public:
    MyHashSet() { v=vector<bool>(1000001,false); }

    void add(int key) { v[key]=true; }

    void remove(int key) { v[key]=false; }

    bool contains(int key) { return v[key]; }
};
int main() {
    MyHashSet obj;      cout<<"null";
    obj.add(1);         cout<<" null";
    obj.add(2);         cout<<" null";
    if(obj.contains(1)) cout<<" true";
    else                cout<<" false"; 
    if(obj.contains(3)) cout<<" true";
    else                cout<<" false";
    obj.add(2);         cout<<" null";
    if(obj.contains(2)) cout<<" true";
    else                cout<<" false";
    obj.remove(2);      cout<<" null";
    if(obj.contains(2)) cout<<" true";
    else                cout<<" false";
}
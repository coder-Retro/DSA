#include<iostream>
#include<vector>
#include"tree.h"
using namespace std;
int main() {
    Tree<int> bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(6);
    bst.insert(5);
    bst.insert(7);

    vector<int> inOrder=bst.inOrder();
    cout<<"InOrder   : "; 
    for(int i:inOrder) cout<<i<<" ";
    cout<<'\n';

    vector<int> preOrder=bst.preOrder();
    cout<<"PreOrder  : "; 
    for(int i:preOrder) cout<<i<<" ";
    cout<<'\n';

    vector<int> postOrder=bst.postOrder();
    cout<<"PostOrder : "; 
    for(int i:postOrder) cout<<i<<" ";
    cout<<'\n';

    vector<vector<int>> levelOrder=bst.levelOrder();
    cout<<"LevelOrder :\n"; 
    for(vector<int>& v:levelOrder) {
        for(int i:v) cout<<i<<" ";
        cout<<'\n';
    }

    return 0;
}
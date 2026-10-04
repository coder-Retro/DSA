#include<iostream>
#include<vector>
#include"tree.h"
using namespace std;
int main() {
    BST<int> bst;
    bst.push(4);
    bst.push(2);
    bst.push(1);
    bst.push(3);
    bst.push(6);
    bst.push(5);
    bst.push(7);

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
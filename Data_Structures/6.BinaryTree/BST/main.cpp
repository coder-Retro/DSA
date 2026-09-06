#include<iostream>
#include<vector>
#include"tree.h"
using namespace std;
int main() {
    Tree<int> bst;
    bst.insertNode(4);
    bst.insertNode(2);
    bst.insertNode(1);
    bst.insertNode(3);
    bst.insertNode(6);
    bst.insertNode(5);
    bst.insertNode(7);

    vector<int> inOrder;
    bst.inOrder(bst.getRoot(), inOrder);
    cout<<"InOrder   : "; 
    for(int i:inOrder) cout<<i<<" ";
    cout<<'\n';

    vector<int> preOrder;
    bst.preOrder(bst.getRoot(), preOrder);
    cout<<"PreOrder  : "; 
    for(int i:preOrder) cout<<i<<" ";
    cout<<'\n';

    vector<int> postOrder;
    bst.postOrder(bst.getRoot(), postOrder);
    cout<<"PostOrder : "; 
    for(int i:postOrder) cout<<i<<" ";
    cout<<'\n';

    vector<vector<int>> levelOrder;
    bst.levelOrder(bst.getRoot(), levelOrder);
    cout<<"LevelOrder :\n"; 
    for(vector<int>& v:levelOrder) {
        for(int i:v) cout<<i<<" ";
        cout<<'\n';
    }

    return 0;
}
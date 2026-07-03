#include<iostream>
#include"tree"
using namespace std;
int main()
{
    tree<int> bst;
    bst.insertNode(4);
    bst.insertNode(2);
    bst.insertNode(1);
    bst.insertNode(3);
    bst.insertNode(6);
    bst.insertNode(5);
    bst.insertNode(7);
    cout<<"InOrder   : "; bst.inOrder(bst.getRoot());
    cout<<'\n';
    cout<<"PreOrder  : "; bst.preOrder(bst.getRoot());
    cout<<'\n';
    cout<<"PostOrder : "; bst.postOrder(bst.getRoot());
    return 0;
}
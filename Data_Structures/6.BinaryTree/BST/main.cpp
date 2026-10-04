#include<iostream>
#include<vector>
#include"tree.h"
using namespace std;

int main() {
    BST<int> bst;

    vector<int> vec={2,3,4,6,1,7,9,0,5,8};
    bst.buildBST(vec);

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

    cout<<"Root's  Val: "<<bst.rootVal()<<'\n';
    cout<<"Minimum Val: "<<bst.minVal()<<'\n';
    cout<<"Maximum Val: "<<bst.maxVal()<<'\n';
    cout<<"Size of BST: "<<bst.size()<<'\n';
    cout<<"Deleting BST ..."<<'\n'; bst.deleteBST();
    cout<<"Size of BST: "<<bst.size()<<'\n';

    return 0;
}
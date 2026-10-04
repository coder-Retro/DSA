#include<iostream>
#include"tree.h"
using namespace std;

int main() {
    BST<int> bst;

    vector<int> vec={2,3,4,6,1,7,9,0,5,8};
    bst.buildBST(vec);

    vector<int> preOrder=bst.preOrder();
    cout<<"PreOrder  : ";
    cout<<"[";
    for(int i=0;i<preOrder.size();i++) {
        cout<<preOrder[i];
        if(i<preOrder.size()-1) cout<<",";
    }
    cout<<"]\n";

    vector<int> inOrder=bst.inOrder();
    cout<<"InOrder   : "; 
    cout<<"[";
    for(int i=0;i<inOrder.size();i++) {
        cout<<inOrder[i];
        if(i<inOrder.size()-1) cout<<",";
    }
    cout<<"]\n";

    vector<int> postOrder=bst.postOrder();
    cout<<"PostOrder : "; 
    cout<<"[";
    for(int i=0;i<postOrder.size();i++) {
        cout<<postOrder[i];
        if(i<postOrder.size()-1) cout<<",";
    }
    cout<<"]\n";

    vector<vector<int>> levels=bst.levelOrder();
    cout<<"LevelOrder :\n"; 
    for(vector<int>& level:levels) {
        cout<<"[";
        for(int i=0;i<level.size();i++) {
            cout<<level[i];
            if(i<level.size()-1) cout<<",";
        }
        cout<<"]\n";
    }

    cout<<"Root's  Val: "<<bst.rootVal()<<'\n';
    cout<<"Minimum Val: "<<bst.minVal()<<'\n';
    cout<<"Maximum Val: "<<bst.maxVal()<<'\n';
    cout<<"Size of BST: "<<bst.size()<<'\n';
    cout<<"Deleting BST ..."<<'\n'; bst.deleteBST();
    cout<<"Size of BST: "<<bst.size()<<'\n';

    return 0;
}
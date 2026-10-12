#include<iostream>
#include"tree.h"
using namespace std;

int main() {
    AVL<int> avl;

    vector<int> vec={2,3,4,6,1,7,9,0,5,8};
    avl.buildAVL(vec);

    vector<int> preOrder=avl.preOrder();
    cout<<"PreOrder  : ";
    cout<<"[";
    for(int i=0;i<preOrder.size();i++) {
        cout<<preOrder[i];
        if(i<preOrder.size()-1) cout<<",";
    }
    cout<<"]\n";

    vector<int> inOrder=avl.inOrder();
    cout<<"InOrder   : "; 
    cout<<"[";
    for(int i=0;i<inOrder.size();i++) {
        cout<<inOrder[i];
        if(i<inOrder.size()-1) cout<<",";
    }
    cout<<"]\n";

    vector<int> postOrder=avl.postOrder();
    cout<<"PostOrder : "; 
    cout<<"[";
    for(int i=0;i<postOrder.size();i++) {
        cout<<postOrder[i];
        if(i<postOrder.size()-1) cout<<",";
    }
    cout<<"]\n";

    vector<vector<int>> levels=avl.levelOrder();
    cout<<"LevelOrder :\n"; 
    for(vector<int>& level:levels) {
        cout<<"[";
        for(int i=0;i<level.size();i++) {
            cout<<level[i];
            if(i<level.size()-1) cout<<",";
        }
        cout<<"]\n";
    }

    cout<<"Root's  Val: "<<avl.rootVal()<<'\n';
    cout<<"Minimum Val: "<<avl.minVal()<<'\n';
    cout<<"Maximum Val: "<<avl.maxVal()<<'\n';
    cout<<"Size of AVL: "<<avl.size()<<'\n';
    cout<<"Height of AVL: "<<avl.height()<<'\n';
    cout<<"Deleting AVL ..."<<'\n'; avl.deleteAVL();
    cout<<"Size of AVL: "<<avl.size()<<'\n';
    cout<<"Height of AVL: "<<avl.height()<<'\n';

    return 0;
}
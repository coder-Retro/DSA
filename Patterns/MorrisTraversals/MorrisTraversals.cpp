#include<iostream>
using namespace std;

/*
Morris PreOrder/InOrder Traversal:
This is a special type of binary tree traversal that allows us
to traverse a binary tree in "PreOrder / InOrder" manner which
uses neither recursion nor a stack. It iterates using temporary
threads (pointer connections), which gives O(1) Space complexity.
This is a space efficient form of binary tree traversal pattern
and is often used where O(1) SC is compulsory. Morris is also
possible for postOrder, however that is the most tricky one which
requires multiple helper functions. Note: It is unsafe because it
temporarily modifies the tree, and can cause the following problems:
1. If an exception is thrown midway, the tree might be left with leftover threads.
2. If multiple executions read the tree at the same time, they might disturb each other.
Following is the code of PreOrder and InOrder manner:
*/

// TreeNode Definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Morris PreOrder Function
void morrisPreOrder(TreeNode* root) {
    TreeNode* curr=root;
    while(curr) {
        if(!curr->left) {
            cout<<curr->val<<" ";
            curr=curr->right;
        } else {
            // Finding InOrder Predecessor
            TreeNode* pred=curr->left;
            while(pred->right && pred->right!=curr) pred=pred->right;
            if(!pred->right) {
                cout<<curr->val<<" "; // Print Root then go left
                pred->right=curr; // Creating Thread
                curr=curr->left;
            } else {
                pred->right=nullptr; // Removing Thread
                curr=curr->right;
            }
        }
    }
}

// Morris InOrder Function
void morrisInOrder(TreeNode* root) {
    TreeNode* curr=root;
    while(curr) {
        if(!curr->left) {
            cout<<curr->val<<" ";
            curr=curr->right;
        } else {
            // Finding InOrder Predecessor
            TreeNode* pred=curr->left;
            while(pred->right && pred->right!=curr) pred=pred->right;
            if(!pred->right) {
                pred->right=curr; // Creating Thread
                curr=curr->left;
            } else {
                pred->right=nullptr; // Removing Thread
                cout<<curr->val<<" ";
                curr=curr->right;
            }
        }
    }
}
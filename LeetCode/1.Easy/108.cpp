#include<vector>
using namespace std;

// Helper Definition & Functions
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Approach: Recursion / Divide And Conquer
TC: O(n)
SC: O(log n)
*/

class Solution {
    TreeNode* makeBST(vector<int>& nums,int l,int r) {
        if(l>r) return nullptr;
        int mid=l+(r-l)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=makeBST(nums,l,mid-1);
        node->right=makeBST(nums,mid+1,r);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums,0,nums.size()-1);
    }
};
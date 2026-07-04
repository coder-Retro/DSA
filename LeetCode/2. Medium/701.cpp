struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode=new TreeNode(val);
        if(!root) { root=newNode; return root; }
        TreeNode* temp=root;
        while(1) {
            if(val<temp->val)
                if(temp->left) temp=temp->left;
                else { temp->left=newNode; break;  }
            else
                if(temp->right) temp=temp->right;
                else { temp->right=newNode; break; }
        }
        return root;
    }
};
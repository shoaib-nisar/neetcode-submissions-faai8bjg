/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool BST(TreeNode* root,long mini,long maxi)
    {
        if(!root) return true;
        if(root->val<=mini || root->val>=maxi) return false;
        
        return (BST(root->left,mini,root->val) && BST(root->right,root->val,maxi));
    }
    bool isValidBST(TreeNode* root) {
       return BST(root,INT_MIN,INT_MAX);
    }
};

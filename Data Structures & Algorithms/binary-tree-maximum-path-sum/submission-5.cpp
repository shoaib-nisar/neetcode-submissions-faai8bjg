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
int maxi=INT_MIN;
    int maxPath(TreeNode* root,int & maxi)
    {
        if(!root) return 0;

        int l=maxPath(root->left,maxi);
        int r=maxPath(root->right,maxi);
        maxi=max(maxi,root->val+l+r);
        maxi=max(maxi,root->val);

        return (max(l,r)<0)?root->val:root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        return max(maxPath(root,maxi),maxi);
    }
};

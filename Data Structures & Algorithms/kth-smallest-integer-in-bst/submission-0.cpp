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
    int Smallest(TreeNode* root,int k,int& c)
    {
        if(!root) return NULL;

        int l=Smallest(root->left,k,c);
        if(l) return l;
        c++;
        if(c==k) return root->val;
        int r=Smallest(root->right,k,c);
        return l?l:r;
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        return Smallest(root,k,c);
    }
};

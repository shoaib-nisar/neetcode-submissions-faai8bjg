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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        int i=0;
        for(auto it:inorder)
        {
            mpp[it]=i++;
        }
        TreeNode* root=builder(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mpp);
        return root;
    }
    TreeNode* builder(vector<int>& preorder, vector<int>& inorder, int preStart,int preEnd,int inStart, int inEnd,unordered_map<int,int>& mpp)
    {
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root=new TreeNode(preorder[preStart]);

        int inRoot=mpp[preorder[preStart]];
        int numsL=inRoot-inStart;

        root->left=builder(preorder,inorder,preStart+1,preStart+numsL,inStart,inRoot-1,mpp);

        root->right=builder(preorder,inorder,preStart+numsL+1,preEnd,inRoot+1,inEnd,mpp);

        return root;
    }
};

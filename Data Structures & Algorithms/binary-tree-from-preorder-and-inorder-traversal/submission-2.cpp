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
    TreeNode* builder(vector<int>& p,int pS,int pE,vector<int>& i,int iS,int iE,map<int,int>& mpp)
    {
        if(pS>pE || iS>iE) return NULL;
        int r=p[pS];
        int idx=mpp[r];
        int numsL=idx-iS;


        TreeNode* root=new TreeNode(r);
        root->left=builder(p,pS+1,pS+numsL,i,iS,idx-1,mpp);
        root->right=builder(p,pS+numsL+1,pE,i,idx+1,iE,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        return builder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
};

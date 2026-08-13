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
    int goodNodes(TreeNode* root) {
    queue<pair<TreeNode*,int>>q;
    int c=0;
    if(root) q.push({root,root->val});
    while(!q.empty())
    {
        TreeNode* temp=q.front().first;
        int maxi=q.front().second;
        q.pop();
        if(temp->val>=maxi) c++;
        if(temp->left) q.push({temp->left,max(maxi,temp->left->val)});
        if(temp->right) q.push({temp->right,max(maxi,temp->right->val)});
    }

    return c;
 
    }
};

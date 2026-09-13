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
    int c=0;
    stack<int> st;
    void DFS(TreeNode* root,int & c)
    {
        if(!root) return;
        if(root->val>=st.top()){
            c++; 
            st.push(root->val);
        }
        DFS(root->left,c);
        if(root->left && st.top()==root->left->val) st.pop();
        DFS(root->right,c);
        if(root->right && st.top()==root->right->val) st.pop();

        return;

    }
    int goodNodes(TreeNode* root) {
        st.push(INT_MIN);
        DFS(root,c);
        return c;
    }
};

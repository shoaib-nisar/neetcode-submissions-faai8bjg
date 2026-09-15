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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        queue<TreeNode*> q;
        if(!root) return s;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr)
            s.append(to_string(curr->val)+",");
            else
            s.append("#,");

            if(curr)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        queue<TreeNode*> q;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode* curr=new TreeNode(stoi(str));
        q.push(curr);
        while(!q.empty())
        {
            TreeNode* root=q.front();
            q.pop();

            getline(ss,str,',');
            if(str=="#") root->left=NULL;
            else {
                TreeNode* l=new TreeNode(stoi(str));
                root->left=l;
                q.push(l);
            }

            getline(ss,str,',');
            if(str=="#") root->right=NULL;
            else {
                TreeNode* r=new TreeNode(stoi(str));
                root->right=r;
                q.push(r);
            }


        }

    return curr;
    }
};

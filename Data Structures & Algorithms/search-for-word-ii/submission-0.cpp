struct Node{
    Node* arr[26]={NULL};
    bool flag=0;
    bool containsKey(char ch)
    {
        return (arr[ch-'a']!=NULL);
    }
};
class Solution {
public:
Node* root=new Node();
     void insert(string word,Node* curr)
    {
        for(int i=0;i<word.size();i++)
        {
            if(!curr->containsKey(word[i]))
            curr->arr[word[i]-'a']=new Node();

            curr=curr->arr[word[i]-'a'];
        }
        curr->flag=1;
    }

    void WordSearch(int i,int j,vector<vector<char>>& board,Node* curr,string s,vector<string>& ans,vector<vector<int>>& vis)
    {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j] || !curr->containsKey(board[i][j])) return;
        curr=curr->arr[board[i][j]-'a'];

          if (curr->flag) {
            ans.push_back(s+board[i][j]);
            curr->flag = false; 
        }

        vis[i][j]=1;
        
        WordSearch(i-1,j,board,curr,s+board[i][j],ans,vis);
        WordSearch(i,j-1,board,curr,s+board[i][j],ans,vis);
        WordSearch(i+1,j,board,curr,s+board[i][j],ans,vis);
        WordSearch(i,j+1,board,curr,s+board[i][j],ans,vis);
        vis[i][j]=0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* curr=root;
        vector<vector<int>> vis(board.size(),vector<int> (board[0].size(),0));
        vector<string> ans;
        string s="";
        for(auto it: words)
        {
            insert(it,curr);
        }

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                WordSearch(i,j,board,root,s,ans,vis);
            }
        }
        return ans;
    }
};

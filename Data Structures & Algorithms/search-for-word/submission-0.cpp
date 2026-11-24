class Solution {
public:
bool Recursion(int i,int j,vector<vector<char>>& board, string word,int idx,vector<vector<int>>& vis)
{
    if(idx==word.size()) return true;
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j] || board[i][j]!=word[idx])
    {
        return false;
    }
    vis[i][j]=1;
    bool res= Recursion(i-1,j,board,word,idx+1,vis) || Recursion(i,j-1,board,word,idx+1,vis) || Recursion(i+1,j,board,word,idx+1,vis) || Recursion(i,j+1,board,word,idx+1,vis);
    vis[i][j]=0;
    return res;
}
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int> (board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            if(Recursion(i,j,board,word,0,vis)) return true;
        }
        return false;
    }
};

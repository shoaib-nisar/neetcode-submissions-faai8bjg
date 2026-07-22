class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     bool Row[9][9]={false};   
     bool Col[9][9]={false};   
     bool Box[9][9]={false};


     for(int i=0;i<9;i++)
     {
        for(int j=0;j<9;j++)
        {
            char ch=board[i][j];
            if(ch=='.') continue;
            int idx=ch-'1';
            int id=3*(i/3)+j/3;
            if(Row[i][idx] || Col[j][idx] || Box[id][idx])
            return false;
            else
            {
                Row[i][idx]=true;
                Col[j][idx]=true;
                Box[id][idx]=true;
            }
            
        }
     }   
     return true;
    }
};

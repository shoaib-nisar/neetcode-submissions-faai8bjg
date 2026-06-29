class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> col(9);
        vector<vector<char>> box(9);
        char elem;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                elem=board[i][j];

                if(elem!='.')
                {
                    if(count(board[i].begin(),board[i].end(),elem)>1)
                    return false;

                    if(find(col[j].begin(),col[j].end(),elem)==col[j].end())
                    {
                        col[j].push_back(elem);
                    }
                    else return false;
                    
                    int boxid= (i/3)*3 + j/3;
                    if(find(box[boxid].begin(),box[boxid].end(),elem)==box[boxid].end())
                    {
                        box[boxid].push_back(elem);
                    }
                    else return false;
                }
                
            }
           
        }
         return true;
    }
};

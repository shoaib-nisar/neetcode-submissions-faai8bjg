class Solution {
public:
void Recursion(vector<string>& vec,
        vector<vector<string>>& ans,
       vector<int>& row,
        vector<int>& lDiag,
        vector<int>& rDiag,int j,int n)
{
    if(j==n)
    {
        ans.push_back(vec);
        return;
    }
    // if(row[i][j] || lDiag[i+j] || rDiag[i+n-j-1])
    // return;

    for(int i=0;i<n;i++)
    {
        if(!row[i] && !lDiag[i+j] && !rDiag[i+n-j-1]){
        vec[i][j]='Q';
        row[i]=1;
        lDiag[i+j]=1;
        rDiag[i+n-j-1]=1;
        Recursion(vec,ans,row,lDiag,rDiag,j+1,n);
        vec[i][j]='.';
        row[i]=0;
        lDiag[i+j]=0;
        rDiag[i+n-j-1]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> vec(n,string(n,'.'));
        vector<vector<string>> ans;
       vector<int> row(n,0);
        vector<int> lDiag(2*n-1,0);
        vector<int> rDiag(2*n-1,0);
        Recursion(vec,ans,row,lDiag,rDiag,0,n);
        return ans;
    }
};

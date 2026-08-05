class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,m=matrix.size(),n=matrix[0].size(),h=m*n-1,mid=0;

        while(l<=h)
        {
            mid=(l+h)/2;
            int row=mid/n,col=mid%n;
            if(matrix[row][col]<target) l=mid+1;
            else if(matrix[row][col]>target) h=mid-1;
            else return true;
        }
        return false;
    }
};

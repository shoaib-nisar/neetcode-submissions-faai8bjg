class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,h=matrix[0].size()-1,mid=0,k=0;
        int m=matrix.size(),n=matrix[0].size();

        while(k<matrix.size() && l<=h)
        {
            if(target<=matrix[k][matrix[0].size()-1])
            {
                mid=l+(h-l)/2;
                if(matrix[k][mid]>target)
                h=mid-1;
                else if(matrix[k][mid]<target)
                l=mid+1;
                else
                return true;
            }
            else
            k++;
        }
        return false;
    }
};

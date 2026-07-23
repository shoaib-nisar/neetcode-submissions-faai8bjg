class Solution {
public:
    int maxArea(vector<int>& heights) {
    int l=0,r=heights.size()-1;
    int maxW=0,W=0;

    while(l<r)
    {
        W=(r-l)*min(heights[l],heights[r]);
        maxW=max(W,maxW);

        if(heights[l]<=heights[r]) l++;
        else r--;
    }    
    return maxW;
    }
};

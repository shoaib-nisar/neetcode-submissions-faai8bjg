class Solution {
public:
    int maxArea(vector<int>& heights) {
    int l=0,r=heights.size()-1;
    int maxArea=0,len=0;
    while(l<r)
    {
        len=min(heights[l],heights[r]);
        int area=len*(r-l);
        maxArea=max(area,maxArea);

        if(heights[l]<=heights[r])
        l++;
        else
        r--;

    }
    return maxArea;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
     int water=0,l=0,r=height.size()-1;   
     int maxL=height[l],maxR=height[r];
     while(l<r)
     {
        if(height[l]<=height[r])
        {
            l++;
            if(height[l]<maxL)
            water+=(maxL-height[l]);
            else
            maxL=height[l];
        }
        else
        {
            r--;
            if(height[r]<maxR)
            water+=(maxR-height[r]);
            else
            maxR=height[r];
        }
     }
     return water;
    }
};

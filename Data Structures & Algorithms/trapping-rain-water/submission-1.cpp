class Solution {
public:
    int trap(vector<int>& height) {
      int l=0,r=height.size()-1;
    int maxL=height[l],maxR=height[r],W=0;
    while(l<r){
      if(maxL<=maxR)
      {
        l++;
        maxL=max(maxL,height[l]);
        W+=maxL-height[l];
      }
      else
      {
        r--;
        maxR=max(maxR,height[r]);
        W+=maxR-height[r];
      }
    }
    return W;
    }
};

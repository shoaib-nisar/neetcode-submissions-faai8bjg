class Solution {
public:
    int characterReplacement(string s, int k) {
      unordered_map<char,int>mpp;
      int l=0,r=0;
      int maxL=0,maxCount=0;
      char maxC;
      while(r<s.size())
      {
        mpp[s[r]]++;
        if(maxCount<mpp[s[r]])
        {
          maxCount=mpp[s[r]];
          maxC=s[r];
        }

        if((r-l+1)-maxCount<=k)
        maxL=max(maxL,r-l+1);
        else if((r-l+1)-maxCount>k)
        {
          if(s[l]==maxC)
          {
            maxCount--;
          }
          mpp[s[l]]--;
          l++;
        }

        r++;
      }  
      return maxL;
    }
};

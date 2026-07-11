class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     unordered_map<char,int> mpp;
      int l=0,r=0;
      int maxL=0;
      
      while(r!=s.size())
      {
        if(mpp.find(s[r])==mpp.end())
        {
          mpp[s[r]]=r;
        }
        else
        {
          maxL=max(maxL,r-l);
          int duplicate=mpp[s[r]]+1;
          while(l!=duplicate)
          {
            mpp.erase(s[l]);
            l++;
          }
          mpp[s[r]]=r;
        }
        r++;
      }
      return max(maxL,r-l);
    }
};

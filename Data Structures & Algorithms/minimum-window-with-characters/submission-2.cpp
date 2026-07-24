class Solution {
public:
    string minWindow(string s, string t) {
       int l=0,r=0,c=0,m=0,minL=INT_MAX,st=0;
       unordered_map<int,int> mpp;
      for(auto it:t)
      {
          mpp[it]++;
      }
      for(auto it:mpp)
      m++;


       while(r!=s.size())
       {
        if(mpp[s[r]]==1)
        c++;
          mpp[s[r]]--;

        while(c==m)
        {
          mpp[s[l]]++;
          if(mpp[s[l]]==1) c--;
          if(r-l+1<minL)
          {
            minL=r-l+1;
          st=l;
          }
          l++;
        }  
        r++;
       } 
       return minL==INT_MAX ? "":s.substr(st,minL);
    }
};

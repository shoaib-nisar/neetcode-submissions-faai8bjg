class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      unordered_map<char,int> mpp;
      unordered_map<char,int> spp;
     int l=0,r=0;
     for(auto it:s1)
     {
      mpp[it]++;
     }
     while(r!=s2.size())
     {
       if((r-l+1)==s1.size())
       {
            
          if(mpp.find(s2[r])!=mpp.end())
            spp[s2[r]]++;
          
          if(mpp==spp)
          return true; 

          
          if(spp.find(s2[l])!=spp.end())
            spp[s2[l]]--;
            l++;
            r++;
       }
       else
       {
        if(mpp.find(s2[r])!=mpp.end())
        spp[s2[r]]++;
        r++;
       }
     }

     return false;

    }
};

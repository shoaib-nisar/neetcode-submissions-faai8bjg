class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        int c=0,mc=0,l=0,r=0,minL=INT_MAX,st=-1;

        for(auto it:t)
        {
          mpp[it]++;
          mc++;
        }

       while(r!=s.size())
       {
         if(mpp[s[r]]>0) c++;
         mpp[s[r]]--;
         while(c==mc)
         {
            if(minL > r-l+1){
            minL=r-l+1;
            st=l;
         }
            mpp[s[l]]++;
            if(mpp[s[l]]>0) c--;
            l++;
         }   
         r++;    
       }
       return (st==-1)?"":s.substr(st,minL);
    }
};

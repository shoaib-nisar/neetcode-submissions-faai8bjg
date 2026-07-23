class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxf=0,maxL=0;
        unordered_map<char,int> mpp;

        while(r!=s.size())
        {
            mpp[s[r]]++;

            maxf=max(maxf,mpp[s[r]]);

            if(r-l+1-maxf>k)
            {
                mpp[s[l]]--; maxf=0;
                l++;
            }

            if(r-l+1-maxf<=k)
            maxL=max(maxL,r-l+1);
            r++;
        }
        return maxL;
    }
};

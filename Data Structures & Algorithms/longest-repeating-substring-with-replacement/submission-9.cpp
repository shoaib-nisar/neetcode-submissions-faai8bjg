class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxF=0,maxL=0;
        unordered_map<char,int> mpp;
        while(r!=s.size())
        {
            mpp[s[r]]++;
            maxF=max(maxF,mpp[s[r]]);

            if((r-l+1)-maxF>k)
            {
                mpp[s[l]]--;
                l++;
                maxF=0;
            }

            if((r-l+1)-maxF<=k)
            {
                maxL=max(maxL,r-l+1);
            }
            r++;
        }
        return maxL;
    }
};

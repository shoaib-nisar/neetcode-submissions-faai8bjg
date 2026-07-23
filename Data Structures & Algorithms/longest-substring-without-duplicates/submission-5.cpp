class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int l=0,r=0,maxL=0;
    unordered_set<char> st;
     while(r!=s.size())
     {
        if(st.find(s[r])==st.end())
        {
            st.insert(s[r]);
            r++;
        }
        else{
            maxL=max(maxL,r-l);
            while(s[l]!=s[r])
            {
                st.erase(s[l++]);
            }
            l++;
            r++;
        } 
     } 
     maxL=max(maxL,r-l);  
     return maxL;
    }
};

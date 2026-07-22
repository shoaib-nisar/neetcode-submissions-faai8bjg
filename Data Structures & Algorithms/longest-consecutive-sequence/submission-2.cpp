class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> st;
        int maxL=0;
       for(auto it:nums)
       {
        st.insert(it);
       } 

       for(auto it:nums)
       {
            if(st.find(it-1)==st.end())
            {
                int len=0;
                while(st.find(it++)!=st.end())
                {
                    len++;
                }
                maxL=max(maxL,len);
            }
       }
       return maxL;
    }
};

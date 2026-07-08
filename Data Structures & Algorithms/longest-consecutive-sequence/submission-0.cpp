class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int maxLen=0;
    unordered_set<int> st;

    for(auto it:nums)
    {
        st.insert(it);
    }

    for(auto it:nums)
    {
        if(st.find(it-1)==st.end())
        {
            int target=it+1;
            int len=1;
            while(st.find(target)!=st.end())
            {
                len++;
                target++;
            }
            maxLen=max(len,maxLen);
        }
    }

    return maxLen;
    }
};

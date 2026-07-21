class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>> vec;
        for(auto s:strs)
        {
            int c[26]={0};

            for(auto ch:s)
            c[ch-'a']++;
            
            string str="";
            for(auto it:c)
            str+=it;

            mpp[str].push_back(s);
        }

        for(auto it:mpp)
        vec.push_back(it.second);

        return vec;
    }
};

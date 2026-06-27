class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string,vector<string>> mpp;
     vector<vector<string>> v;
     for(int i=0;i<strs.size();i++)
     {
        string str=strs[i];
        sort(str.begin(),str.end());
        mpp[str].push_back(strs[i]);
     }  
     for(auto it:mpp)
     {
        v.push_back(it.second);
     }
     return v;
    }
};

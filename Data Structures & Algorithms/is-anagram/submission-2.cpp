class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        unordered_map<char,int> spp;

        for(auto it:s)
        mpp[it]++;

        for(auto it:t)
        spp[it]++;

        if(mpp==spp)
        return true;
        else return false;
    }
};

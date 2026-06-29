class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<vector<int>> v(nums.size()+1);
        vector<int> res;
        for(auto it:nums)
        {
            mpp[it]++;
        }

        for(auto it:mpp)
        {
            v[it.second].push_back(it.first);
        }

        for(int i=nums.size();i>=0;i--)
        {
            for(auto it:v[i])
            res.push_back(it);

            if(res.size()==k)
            break;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> mpp;
      multimap<int,int,greater<int>> spp;
      vector<int> v;
       for(auto it:nums)
       {
            mpp[it]++;
       }
       for(auto it:mpp)
       {
        spp.insert({it.second,it.first});
       }

       for(auto it:spp)
       {
            if(k>0)
            {
                v.push_back(it.second);
                k--;
            }
            else
            return v;
       }

    }
};

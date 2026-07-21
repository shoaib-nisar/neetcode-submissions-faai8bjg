class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<vector<int>>arr(nums.size()+1);

      unordered_map<int,int> mpp;

      for(auto it:nums)
      {
        mpp[it]++;
      } 

      for(auto it:mpp)
      {
        arr[it.second].push_back(it.first);
      }

      vector<int> vec;
      for(int i=arr.size()-1;i>=0 && vec.size()<k;i--)
      {
        for(auto it:arr[i])
        {
            vec.push_back(it);
            if(vec.size()==k) return vec;
        }
      }
      return vec;
    }
};

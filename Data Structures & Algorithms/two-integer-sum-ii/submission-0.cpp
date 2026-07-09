class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int,int> mpp;
    int i=0;
      for(auto it:numbers) 
      {
        mpp[it]=i++;
      }

      for(i=0;i<numbers.size();i++)
      {
         int comp=target-numbers[i];
         if(mpp.find(comp)!=mpp.end())
         {
            if(mpp.find(comp)->second!=i)
            return {i+1,mpp.find(comp)->second+1};
         }
      }
    }
};

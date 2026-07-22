class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      unordered_map<int,int> mpp;

      for(int i=0;i<numbers.size();i++)
      {
        mpp[numbers[i]]=i+1;
      }   

      for(auto it:numbers)
      {
        if(mpp.find(target-it)!=mpp.end()) return {mpp[it],mpp[target-it]};
      }
    }
};

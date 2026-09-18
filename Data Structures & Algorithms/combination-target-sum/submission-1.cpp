class Solution {
public:
    void Recursive(int i,vector<int>& nums, int target,vector<int>& v,vector<vector<int>>& vec)
    {
        if(i==nums.size()) return;
        if(target==0)
        {
            vec.push_back(v);
            return;
        }
        if(nums[i]>target) return;
        v.push_back(nums[i]);
        Recursive(i,nums,target-nums[i],v,vec);
        v.pop_back();
        Recursive(i+1,nums,target,v,vec);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
         vector<vector<int>> vec;
        vector<int> v;
       sort(nums.begin(),nums.end());
       Recursive(0,nums,target,v,vec); 
       return vec;
    }
};

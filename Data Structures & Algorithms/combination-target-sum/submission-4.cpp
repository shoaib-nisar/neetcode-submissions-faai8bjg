class Solution {
public:
    void Recursive(vector<int>&nums, vector<vector<int>>&vec, vector<int>&v,int  target , int i)
    {
        if(target==0)
        {
            vec.push_back(v);
            return;
        }
        if(i>=nums.size())return;
        if(target<nums[i])
        return;
        v.push_back(nums[i]);
        Recursive(nums,vec,v,target-nums[i],i);

        v.pop_back();
        Recursive(nums,vec,v,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> vec;
         vector<int> v;
         sort(nums.begin(),nums.end());
        Recursive(nums,vec,v,target,0);
        return vec;
    }
};

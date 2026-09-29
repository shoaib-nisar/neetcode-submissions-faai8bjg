class Solution {
public:
    void Recursive(vector<int>& nums,vector<vector<int>>& vec,int idx)
    {
        if(idx==nums.size())
        {
            vec.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            Recursive(nums,vec,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vec;
        Recursive(nums,vec,0);
        return vec;
    }
};

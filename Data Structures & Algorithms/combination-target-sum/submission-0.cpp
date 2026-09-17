class Solution {
public:
    void Recursive(int i,int sum,vector<int>&nums,int target,vector<vector<int>>& vec,vector<int>& v)
    {
        while(i!=nums.size())
        {
            sum+=nums[i];
            v.push_back(nums[i]);
            if(sum>target){
            v.pop_back();
            return;}
            else if(sum==target)
            {
                vec.push_back(v);
                v.pop_back();
                return;
            }
            Recursive(i,sum,nums,target,vec,v);
            sum-=nums[i];
            v.pop_back();
            i++;
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> vec;
        vector<int> v;
       sort(nums.begin(),nums.end());
       Recursive(0,0,nums,target,vec,v); 
       return vec;
    }
};

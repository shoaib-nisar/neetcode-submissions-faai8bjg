class Solution {
public:
    void Recursive(vector<int>& nums,vector<vector<int>>& vec, unordered_map<int,int>& vis,vector<int>& v)
    {
        if(v.size()==nums.size())
        {
            vec.push_back(v); return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                v.push_back(nums[i]);
                Recursive(nums,vec,vis,v);
                v.pop_back();
                vis[i]=0;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> v;
        unordered_map<int,int> vis;
        Recursive(nums,vec,vis,v);
        return vec;
    }
};

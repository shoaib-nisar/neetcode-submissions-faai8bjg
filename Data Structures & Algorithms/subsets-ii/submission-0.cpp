class Solution {
public:
    void Recursive(int i,vector<int>& nums,vector<int>& v,vector<vector<int>>& vec)
    {
        if(i==nums.size())
        {
            vec.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        Recursive(i+1,nums,v,vec);
        v.pop_back();
        while(i!=nums.size()-1 && nums[i+1]==nums[i]) i++;
        Recursive(i+1,nums,v,vec);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> vec;
        vector<int> v;
       Recursive(0,nums,v,vec); 
       return vec;
    }
};

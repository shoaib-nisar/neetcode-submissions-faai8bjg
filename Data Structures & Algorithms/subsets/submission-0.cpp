class Solution {
public:
    void Subset(int i,vector<int>& nums,vector<int>& v,vector<vector<int>>& vec)
    {
        if(i>=nums.size()){
          vec.push_back(v);  return;
        }
        
        //Forward recursion
        v.push_back(nums[i]);
        i++;
        Subset(i,nums,v,vec);

        v.pop_back();
        Subset(i,nums,v,vec);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> v;
        Subset(0,nums,v,vec);
        return vec;
    }
};

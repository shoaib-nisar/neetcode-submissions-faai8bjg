class Solution {
public:
    void Recursive(int i,vector<int>& candidates, int target,vector<int>& v,vector<vector<int>>& vec)
    {
        
        if(target==0)
        {
            vec.push_back(v);
            return;
        }
        if(i==candidates.size()) return;
        if(candidates[i]>target) return;
        v.push_back(candidates[i]);
        Recursive(i+1,candidates,target-candidates[i],v,vec);
        v.pop_back();
        while(i!=candidates.size()-1 && candidates[i+1]==candidates[i]) i++;
        Recursive(i+1,candidates,target,v,vec);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> vec;
        vector<int> v;
       sort(candidates.begin(),candidates.end());
       Recursive(0,candidates,target,v,vec); 
       return vec; 
    }
};

class Solution {
public:
    void Recursive(vector<int>&candidates, vector<vector<int>>&vec, vector<int>&v,int  target , int i)
    {
        if(target==0)
        {
            vec.push_back(v);
            return;
        }
        if(i>=candidates.size())return;
        if(target<candidates[i])
        return;
        v.push_back(candidates[i]);
        Recursive(candidates,vec,v,target-candidates[i],i+1);

        v.pop_back();
        int elem=candidates[i++];
        while(i!=candidates.size() && elem==candidates[i]) i++;
        Recursive(candidates,vec,v,target,i);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     vector<vector<int>> vec;
         vector<int> v;
         sort(candidates.begin(),candidates.end());
        Recursive(candidates,vec,v,target,0);
        return vec;   
    }
};

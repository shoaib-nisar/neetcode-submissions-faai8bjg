class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> t;
        for(int i=0;i<nums.size();i++)
        {
            unordered_multiset<int> st;
            for(int j=i+1;j<nums.size();j++)
            {
                int third=-(nums[i]+nums[j]);
                if(st.find(third)!=st.end())
                {
                    vector<int> v={nums[i],nums[j],third};
                    sort(v.begin(),v.end());
                    t.insert(v);
                }
                st.insert(nums[j]);
            }
        }
        vector<vector<int>> res(t.begin(),t.end());
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            l=i+1;
            r=nums.size()-1;
            while(l<r)
            {
                if(nums[l]+nums[r]+nums[i]<0) l++;
                else if(nums[l]+nums[r]+nums[i]>0) r--;
                else {
                    st.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
            }
        }
        vector<vector<int>> vec(st.begin(),st.end());
        return vec;
    }
};

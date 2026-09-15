class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n;
        while(true)
        {
             n=nums[0];
            if(n==nums[n]) return n;
            swap(nums[0],nums[n]);
        }
    }
};

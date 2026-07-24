class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int l=0,r=0;
       vector<int>vec1;
       

       while(r!=nums.size())
       {
        
        if(r-l+1==k)
        {
          vector<int>vec2(nums.begin()+l,nums.begin()+r+1);
          sort(vec2.begin(),vec2.end());

          vec1.push_back(vec2[k-1]);

          l++;
        }


        r++;
       } 
       return vec1;
    }
};

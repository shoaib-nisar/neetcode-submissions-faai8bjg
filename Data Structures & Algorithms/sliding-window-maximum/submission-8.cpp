class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int l=0,r=0;
      vector<int> vec;
      priority_queue<int> q;
      unordered_map<int,int> mpp;
      while(r!=nums.size())
      {
        q.push(nums[r]);

        if(r-l+1==k)
        {
          while(mpp[q.top()])
          {
            mpp[q.top()]--;
            q.pop();
          }
          vec.push_back(q.top());
          mpp[nums[l]]++;
          l++;
        }
        r++;
      }
      return vec;  
    }
};
